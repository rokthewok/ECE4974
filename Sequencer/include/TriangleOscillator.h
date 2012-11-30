#ifndef TRIANGLEOSCILLATOR_H
#define TRIANGLEOSCILLATOR_H
#include "Oscillator.h"

class TriangleOscillator : public Oscillator {
public:
	explicit TriangleOscillator( float frequency = 440.0f );
	TriangleOscillator( int sampleRate, float frequency );
    virtual float nextSample();
};

#endif // TRIANGLEOSCILLATOR_H
