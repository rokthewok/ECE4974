#include "include/JackSequencerController.h"

JackSequencerController::JackSequencerController( Sequencer * sequencer )
    : m_sequencer( sequencer ) {

}

void JackSequencerController::init() {
    if( !( m_client = jack_client_open( "sequencer", JackNullOption, NULL ) ) ) {
        this->jackInitError( QString( "could not open client." ) );
    }

    if( !( jack_set_process_callback( m_client, JackSequencerController::doProcess, m_sequencer ) ) ) {
        this->jackInitError( QString( "could not set the process callback." ) );
    }

    m_port = jack_port_register( m_client, "play", JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput, 0 );
}

sample_t JackSequencerController::nextSample() {
    return m_sequencer->nextSample();
}

int JackSequencerController::doProcess( jack_nframes_t nframes, void *args ) {
    JackSequencerController * controller = static_cast<JackSequencerController *>( args );

    sample_t * buffer = (sample_t *) jack_port_get_buffer( controller->getPort(), nframes );

    for( int i = 0; i < nframes; i++ ) {
        buffer[i] = controller->nextSample();
    }

    return 0;
}

jack_client_t * JackSequencerController::getClient() {
    return m_client;
}

jack_port_t * JackSequencerController::getPort() {
    return m_port;
}

void JackSequencerController::addNoteOnBeat( int note, int beat ) {
    m_sequencer->getNotes().at( note )->setBeat( beat );
}

void JackSequencerController::removeNoteOnBeat( int note, int beat ) {
    m_sequencer->getNotes().at( note )->clearBeat( beat );
}
