#include "SineOscillator.h"
#include <iostream>

SineOscillator::SineOscillator( float frequency )
	: Oscillator::Oscillator( frequency ) {

}

SineOscillator::SineOscillator( int sampleRate, float frequency )
	: Oscillator::Oscillator( sampleRate, frequency ) {

}

float SineOscillator::nextSample() {
    float value = sin( m_currentPhase );
	m_currentPhase += m_phaseIncrement;

	if( m_currentPhase > 2.0 * M_PI ) {
		m_currentPhase = 0.0f;
	}

	return value;
}
