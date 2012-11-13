#ifndef RISINGSAWTOOTHOSCILLATOR_H
#define RISINGSAWTOOTHOSCILLATOR_H
#include "Oscillator.h"

class RisingSawtoothOscillator : public Oscillator {
public:
	explicit RisingSawtoothOscillator( float frequency = 440.0f );
	RisingSawtoothOscillator( int sampleRate, float frequency );
	virtual short nextSample();
};

#endif // RISINGSAWTOOTHOSCILLATOR_H
