#ifndef NOTE_H
#define NOTE_H
#include "Oscillator.h"
#include "Wavetype.h"

class Note {
public:
    explicit Note( Wavetype wavetype, Oscillator * oscillator );
    Note( Wavetype wavetype, Oscillator * oscillator, int barLength );
    float nextSample( int beat );
    Oscillator * getOscillator();
    Oscillator * setOscillator( Wavetype wavetype, Oscillator *oscillator );
    float getAmplitude() const;
    void setAmplitude( float amplitude );
    Wavetype getWavetype() const;
    void setSampleRate( int sampleRate );
    void setFrequency( float frequency );
    bool setBeat( int beat );
    bool clearBeat( int beat );
    void clearAllBeats();
    bool isBeatSet( int beat );
    void reset();
private:
    Oscillator * m_oscillator;
    float m_amplitude;
    int m_barLength;
    int * m_beats; // 1 for on, 0 for off
    Wavetype m_wavetype;
};

#endif // NOTE_H
