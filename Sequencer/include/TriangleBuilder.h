#ifndef TRIANGLEBUILDER_H
#define TRIANGLEBUILDER_H

#include "include/OscillatorBuilder.h"

class TriangleBuilder : public OscillatorBuilder {
public:
    virtual Oscillator * buildOscillator(int sampleRate, float frequency);
};

#endif // TRIANGLEBUILDER_H
