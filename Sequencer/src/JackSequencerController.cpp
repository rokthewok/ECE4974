#include "include/JackSequencerController.h"

JackSequencerController::JackSequencerController()
    : m_sequencer( NULL ) {

}

void JackSequencerController::init() {
    if( !( m_client = jack_client_open( "sequencer", JackNullOption, NULL ) ) ) {
        this->jackInitError( QString( "could not open client." ) );
        return;
    }

    if( !( jack_set_process_callback( m_client, &JackSequencerController::doProcess, this ) ) ) {
        this->jackInitError( QString( "could not set the process callback." ) );
    }

    m_outgoingPort = jack_port_register( m_client, "play", JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput, 0 );
}

void JackSequencerController::play() {
    if( m_sequencer != NULL ) {
        if( jack_activate( m_client ) ) {
            this->jackPlayError( QString( "could not activate client." ) );
            return;
        }

        const char ** ports;
        if( ( ports = jack_get_ports( m_client, NULL, NULL, JackPortIsPhysical | JackPortIsInput ) ) == NULL ) {
            this->jackPlayError( QString( "could not get playback ports" ) );
            jack_deactivate( m_client );
            return;
        }

        int i = 0;
        while( ports[i] != NULL ) {
            if( !jack_connect( m_client, jack_port_name( m_outgoingPort ), ports[i] ) ) {
                m_destinationPort = ports[i];
                break;
            }
        }

        free( ports );
    }
}

void JackSequencerController::pause() {
    jack_disconnect( m_client, jack_port_name( m_outgoingPort ), m_destinationPort );
    jack_deactivate( m_client );
}

void JackSequencerController::stop() {
    jack_disconnect( m_client, jack_port_name( m_outgoingPort ), m_destinationPort );
    jack_deactivate( m_client );
    m_sequencer->stop();
}

sample_t JackSequencerController::nextSample() {
    return m_sequencer->nextSample();
}

int JackSequencerController::doProcess( jack_nframes_t nframes, void *args ) {
    JackSequencerController * controller = static_cast<JackSequencerController *>( args );

    sample_t * buffer = (sample_t *) jack_port_get_buffer( controller->getPort(), nframes );

    for( unsigned i = 0; i < nframes; i++ ) {
        buffer[i] = controller->nextSample();
    }

    return 0;
}

jack_client_t * JackSequencerController::getClient() {
    return m_client;
}

jack_port_t * JackSequencerController::getPort() {
    return m_outgoingPort;
}

void JackSequencerController::addNoteOnBeat( int note, int beat ) {
    m_sequencer->setNoteOnBeat( note, beat );
}

void JackSequencerController::removeNoteOnBeat( int note, int beat ) {
    m_sequencer->removeNoteOnBeat( note, beat );
}

Sequencer * JackSequencerController::getSequencer() {
    return m_sequencer;
}

void JackSequencerController::setSequencer( Sequencer * sequencer ) {
    m_sequencer = sequencer;
}
