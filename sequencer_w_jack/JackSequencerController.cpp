#include "JackSequencerController.h"
#include <iostream>
#include "stdlib.h"

JackSequencerController::JackSequencerController()
    : m_sequencer( NULL ) {

}

void JackSequencerController::init() {
    if( !( m_client = jack_client_open( "sequencer", JackNullOption, NULL ) ) ) {
         std::cout << "could not open client." << std::endl;
    }

    if( ( jack_set_process_callback( m_client, &JackSequencerController::doProcess, this ) ) != 0 ) {
        std::cout << "could not set the process callback." << std::endl;
    }

    m_port = jack_port_register( m_client, "play", JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput, 0 );
}

void JackSequencerController::play() {
    if( m_sequencer != NULL ) {
        // do stuff
        if( jack_activate( m_client ) ) {
		std::cout << "Could not activate client." << std::endl;
		return;
	}

	const char ** ports;
	if( ( ports = jack_get_ports( m_client, NULL, NULL, JackPortIsPhysical | JackPortIsInput ) ) == NULL ) {
		std::cout << "cannot get playback ports" << std::endl;
		return;
	}

	int i = 0;
	while( ports[i] != NULL ) {
		if( !jack_connect( m_client, jack_port_name( m_port ), ports[i] ) ) break;
	}
	
	free( ports );
    }
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
    return m_port;
}

void JackSequencerController::setNoteOnBeat( int note, int beat ) {
    m_sequencer->getNotes().at( note )->setBeat( beat );
}

void JackSequencerController::clearNoteOnBeat( int note, int beat ) {
    m_sequencer->getNotes().at( note )->clearBeat( beat );
}

void JackSequencerController::setSequencer( Sequencer * sequencer ) {
    m_sequencer = sequencer;
}
