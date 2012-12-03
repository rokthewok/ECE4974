#include "include/Sequencer.h"

Sequencer::Sequencer( int sampleRate )
    : m_bpm( 100 ),
      m_beat( 0 ),
      m_sampleRate( sampleRate ) {
    m_samplesPerBeat = 1; // TODO something else here
}

Sequencer::Sequencer( int sampleRate, int bpm )
    : m_bpm( bpm ),
      m_beat( 0 ),
      m_sampleRate( sampleRate ) {
    m_samplesPerBeat = 1; // TODO something else here
}

float Sequencer::nextSample() {
    return 0.0f;
}
