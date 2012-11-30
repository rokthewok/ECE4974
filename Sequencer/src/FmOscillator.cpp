#include "include/FmOscillator.h"
#include <math.h>
#include <iostream>

FmOscillator::FmOscillator( int sampleRate, float frequency,
				float harmonicity, float modulationIndex )
	: Oscillator( sampleRate, frequency ),
	  m_harmonicity( harmonicity ),
	  m_modulationIndex( modulationIndex ) {

}

float FmOscillator::nextSample() {
    float sample = sin( m_currentPhase + ( m_modulationIndex * sin( m_harmonicity * m_currentPhase ) ) );
	
	// TODO account for floating point overflow somehow
	// n/m = harmonicity, n = number of 2*PI in currenModulatingPhase, m = number of 2*PI in currentPhase
	m_currentPhase += m_phaseIncrement;

	return sample;
}
