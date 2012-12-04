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
}

sample_t JackSequencerController::nextSample() {
    return m_sequencer->nextSample();
}

void JackSequencerController::doProcess( jack_nframes_t nframes, void *args ) {
    JackSequencerController * controller = static_cast<JackSequencerController *>( args );

    sample_t * buffer = jack_port_get_buffer( controller->getClient(), nframes );

    for( int i = 0; i < nframes; i++ ) {
        buffer[i] = controller->nextSample();
    }
}
