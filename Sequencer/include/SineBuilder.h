#ifndef SINEBUILDER_H
#define SINEBUILDER_H

#include "OscillatorBuilder.h"

class SineBuilder : public OscillatorBuilder {
public:
    virtual Oscillator * buildOscillator( int sampleRate, float frequency );
};

#endif // SINEBUILDER_H
