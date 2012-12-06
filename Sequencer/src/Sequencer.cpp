#include "include/Sequencer.h"
#include "include/Note.h"
#include "include/SineOscillator.h"
#include "include/Pitch.h"

Sequencer::Sequencer( int sampleRate )
    : Sequencer::Sequencer( sampleRate, 400 ) {

}

Sequencer::Sequencer( int sampleRate, int bpm )
    : m_bpm( bpm ),
      m_beat( 0 ),
      m_barLength( 16 ),
      m_decay( 0.1f ),
      m_sampleRate( sampleRate ),
      m_currentRepeat( 0 ) {
    m_samplesPerBeat = calculateSamplesPerBeat( m_sampleRate, m_bpm );
}

void Sequencer::init() {
    m_notes.append( new Note( new SineOscillator( m_sampleRate, F_C4 ), 16 ) );
    m_notes.append( new Note( new SineOscillator( m_sampleRate, F_D4 ), 16 ) );
    m_notes.append( new Note( new SineOscillator( m_sampleRate, F_E4 ), 16 ) );
    m_notes.append( new Note( new SineOscillator( m_sampleRate, F_G4 ), 16 ) );
    m_notes.append( new Note( new SineOscillator( m_sampleRate, F_A4 ), 16 ) );
}

float Sequencer::nextSample() {
    float sample = 0.0f;

    QList<Note *>::iterator it;
    for( it = m_notes.begin(); it != m_notes.end(); it++ ) {
        sample += m_decay * (*it)->nextSample( m_beat ); // TODO keep track of number of notes on a beat, and scale
                                                         // the sample appropriately
    }

    if( m_currentSample % m_samplesPerBeat == 0 ) {
        m_currentSample = 0;
        m_beat++;
        if( m_beat >= m_barLength ) {
            m_beat = 0;
        }
    } else if( m_currentSample < m_samplesPerBeat / 20
               && m_decay < 1.0f ) {
        m_decay += 20.0f / (float) m_samplesPerBeat; // interpolate attack by an appropriate estimate
    } else if( m_samplesPerBeat - m_currentSample < m_samplesPerBeat / 10
               && m_decay > 0.0f ) {
        m_decay -= 10.0f / (float) m_samplesPerBeat; // interpolate decay by an appropriate estimate
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
