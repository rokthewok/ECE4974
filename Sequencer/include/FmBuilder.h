#ifndef FMBUILDER_H
#define FMBUILDER_H

#include "include/OscillatorBuilder.h"
#include "include/FmOscillator.h"

class FmBuilder : public OscillatorBuilder {
public:
    virtual Oscillator * buildOscillator(int sampleRate, float frequency);
};

#endif // FMBUILDER_H
