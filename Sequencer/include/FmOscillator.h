#ifndef FMOSCILLATOR_H
#define FMOSCILLATOR_H
#include "Oscillator.h"

class FmOscillator : public Oscillator {
public:
	FmOscillator( int sampleRate, float frequency,
			float harmonicity, float modulationIndex );
    virtual float nextSample();
    float getHarmonicity() const;
    float getModulationIndex() const;
    void setHarmonicity( float harmonicity );
    void setModulationIndex( float modulationIndex );
private:
	float m_harmonicity;
	float m_modulationIndex;
};

#endif // FMOSCILLATOR_H
