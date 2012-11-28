#include "RisingSawtoothOscillator.h"

RisingSawtoothOscillator::RisingSawtoothOscillator( float frequency )
	: Oscillator::Oscillator( frequency ) {

}

RisingSawtoothOscillator::RisingSawtoothOscillator( int sampleRate, float frequency )
	: Oscillator::Oscillator( sampleRate, frequency ) {

}

short RisingSawtoothOscillator::nextSample() {
	short sample = SHORT_MAX * ( ( 1.0f / M_PI ) * m_currentPhase - 1.0f );

	m_currentPhase += m_phaseIncrement;
	if( m_currentPhase > 2.0f * M_PI ) {
		m_currentPhase = 0.0f;
	}

	return sample;
}
