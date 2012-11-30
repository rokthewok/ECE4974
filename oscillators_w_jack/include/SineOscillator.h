#ifndef SINEOSCILLATOR_H
#define SINEOSCILLATOR_H
#include <math.h>
#include "Oscillator.h"

class SineOscillator : public Oscillator {
public:
	explicit SineOscillator( float frequency = 440.0f );
	SineOscillator( int sampleRate, float frequency );
	virtual float nextSample();
};

#endif // SINEOSCILLATOR_H
