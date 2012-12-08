#ifndef OSCILLATORBUILDER_H
#define OSCILLATORBUILDER_H

#include "include/Oscillator.h"

class OscillatorBuilder {
public:
    virtual ~OscillatorBuilder();
    virtual Oscillator * buildOscillator( int sampleRate, float frequency ) = 0;
};

#endif // OSCILLATORBUILDER_H
