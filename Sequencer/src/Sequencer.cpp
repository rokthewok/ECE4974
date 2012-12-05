#include "include/Sequencer.h"
#include "include/Note.h"
#include "include/SineOscillator.h"
#include "include/Pitch.h"

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
        sample += (*it)->nextSample( m_beat ) / 12.0;
    }

    return 0.0f;
}

int Sequencer::getCurrentRepeat() const {
    return 0;
}

int Sequencer::getSampleRate() const {
    return 0;
}

int Sequencer::getCurrentBeat() const {
    return 0;
}

int Sequencer::getBpm() const {
    return 0;
}

QList<Note *> & Sequencer::getNotes() {
    return m_notes;
}

void Sequencer::setSampleRate() {

}

void Sequencer::setBpm() {

}

void Sequencer::stop() {

}
