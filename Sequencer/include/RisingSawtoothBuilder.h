#ifndef RISINGSAWTOOTHBUILDER_H
#define RISINGSAWTOOTHBUILDER_H

#include "include/OscillatorBuilder.h"

class RisingSawtoothBuilder : public OscillatorBuilder {
public:
    virtual Oscillator * buildOscillator(int sampleRate, float frequency);
};

#endif // RISINGSAWTOOTHBUILDER_H
