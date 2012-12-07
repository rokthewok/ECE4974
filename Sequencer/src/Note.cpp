#include "include/Note.h"

Note::Note( Wavetype wavetype, Oscillator * oscillator )
    : Note::Note( wavetype, oscillator, 16 ){
}

Note::Note( Wavetype wavetype, Oscillator * oscillator, int barLength )
    : m_oscillator( oscillator ),
      m_barLength( barLength ),
      m_beats( new int[barLength] ),
      m_amplitude( 1.0f ),
      m_wavetype( wavetype ) {
}

float Note::nextSample( int beat ) {
    if( beat >= m_barLength || beat < 0 ) {
        return 0.0f;
    }

    return m_amplitude * m_beats[beat] * m_oscillator->nextSample();
}

Oscillator * Note::setOscillator( Wavetype wavetype, Oscillator * oscillator ) {
    Oscillator * temp = m_oscillator;
    m_oscillator = oscillator;
    m_wavetype = wavetype;

    return temp;
}

void Note::setSampleRate( int sampleRate ) {
    m_oscillator->setSampleRate( sampleRate );
}

void Note::setFrequency( float frequency ) {
    m_oscillator->setFrequency( frequency );
}

bool Note::setBeat( int beat ) {
    if( beat >= m_barLength || beat < 0 ) {
        return false;
    }

    m_beats[beat] = 1;
    return true;
}

bool Note::clearBeat( int beat ) {
    if( beat >= m_barLength || beat < 0 ) {
        return false;
    }

    m_beats[beat] = 0;
    return false;
}

void Note::clearAllBeats() {
    for( int i = 0; i < m_barLength; i++ ) {
        m_beats[i] = 0;
    }
}

bool Note::isBeatSet( int beat ) {
    if( m_beats[beat] ) {
        return true;
    } else {
        return false;
    }
}

void Note::reset() {
    m_oscillator->reset();
}

float Note::getAmplitude() const {
    return m_amplitude;
}

void Note::setAmplitude( float amplitude ) {
    m_amplitude = amplitude;
}

Oscillator * Note::getOscillator() {
    return m_oscillator;
}

Wavetype Note::getWavetype() const {
    return m_wavetype;
}
