#include "include/Sequencer.h"
#include "include/Note.h"
#include "include/SineOscillator.h"
#include "include/Pitch.h"

Sequencer::Sequencer( int sampleRate )
    : m_bpm( 100 ),
      m_beat( 0 ),
      m_barLength( 16 ),
      m_currentSample( 0 ),
      m_decay( 1.0f ),
      m_sampleRate( sampleRate ),
      m_currentRepeat( 0 ) {
    m_samplesPerBeat = calculateSamplesPerBeat( m_sampleRate, m_bpm );
}

Sequencer::Sequencer( int sampleRate, int bpm )
    : m_bpm( bpm ),
      m_beat( 0 ),
      m_barLength( 16 ),
      m_decay( 1.0f ),
      m_sampleRate( sampleRate ),
      m_currentRepeat( 0 ) {
    m_samplesPerBeat = calculateSamplesPerBeat( m_sampleRate, m_bpm );
}

void Sequencer::init() {
    m_notes.append( new Note( new SineOscillator( m_sampleRate, F_C3 ) ) );
    m_notes.append( new Note( new SineOscillator( m_sampleRate, F_D3 ) ) );
    m_notes.append( new Note( new SineOscillator( m_sampleRate, F_E3 ) ) );
    m_notes.append( new Note( new SineOscillator( m_sampleRate, F_G3 ) ) );
    m_notes.append( new Note( new SineOscillator( m_sampleRate, F_A3 ) ) );
}

float Sequencer::nextSample() {
    float sample = 0.0f;

    QList<Note *>::iterator it;
    for( it = m_notes.begin(); it != m_notes.end(); it++ ) {
        sample += m_decay * (*it)->nextSample( m_beat ) / 12.0;
    }

    if( m_currentSample % m_samplesPerBeat == 0 ) {
        m_currentSample = 0;
        m_beat++;
        m_decay = 1.0f;
        if( m_beat >= m_barLength ) {
            m_beat = 0;
        }
    } else if( m_samplesPerBeat - m_currentSample < 2000 ) {
        m_decay -= 0.0005; // to go from 1 to 0 in 2000 samples
    }

    m_currentSample++;

    return sample;
}

int Sequencer::getCurrentRepeat() const {
    return m_currentRepeat;
}

int Sequencer::getSampleRate() const {
    return m_sampleRate;
}

int Sequencer::getCurrentBeat() const {
    return m_beat;
}

int Sequencer::getBpm() const {
    return m_bpm;
}

QList<Note *> & Sequencer::getNotes() {
    return m_notes;
}

void Sequencer::setSampleRate( int sampleRate ) {
    m_sampleRate = sampleRate;
    m_samplesPerBeat = calculateSamplesPerBeat( m_sampleRate, m_bpm );
}

void Sequencer::setBpm( int bpm ) {
    m_bpm = bpm;
    m_samplesPerBeat = calculateSamplesPerBeat( m_sampleRate, m_bpm );
}

void Sequencer::stop() {
    m_currentSample = 0;
    m_beat = 0;
    m_decay = 0.0f;
}

int Sequencer::calculateSamplesPerBeat( int sampleRate, int bpm ) {
    return (int) ( (float) sampleRate * 60.0f / (float) bpm );
}
