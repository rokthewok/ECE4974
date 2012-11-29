#ifndef FMOSCILLATOR_H
#define FMOSCILLATOR_H
#include "Oscillator.h"

class FmOscillator : public Oscillator {
public:
	FmOscillator( int sampleRate, float frequency,
			float harmonicity, float modulationIndex );
	virtual short nextSample();
private:
	float m_harmonicity;
	float m_modulationIndex;
};

#endif // FMOSCILLATOR_H
