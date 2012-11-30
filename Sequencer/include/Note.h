#ifndef NOTE_H
#define NOTE_H
#include "Oscillator.h"

class Note {
public:
    explicit Note( Oscillator * oscillator );
    Note( Oscillator * oscillator, int barLength );
    float nextSample( int beat );
    Oscillator * setOscillator( Oscillator * oscillator );
    void setSampleRate( int sampleRate );
    void setFrequency( float frequency );
    bool setBeat( int beat );
    bool clearBeat( int beat );
    void clearAllBeats();
private:
    Oscillator * m_oscillator;
    float m_amplitude;
    int m_barLength;
    int * m_beats; // 1 for on, 0 for off
};

#endif // NOTE_H
