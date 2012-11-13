#include "SineOscillator.h"

SineOscillator::SineOscillator( float frequency )
	: Oscillator::Oscillator( frequency ) {

}

SineOscillator::SineOscillator( int sampleRate, float frequency )
	: Oscillator::Oscillator( sampleRate, frequency ) {

}

short SineOscillator::nextSample() {
	short value = SHORT_MAX * sin( m_currentPhase );
	m_currentPhase += m_phaseIncrement;

	if( m_currentPhase > 2.0 * M_PI ) {
		m_currentPhase = 0.0f;
	}

	return value;
}
