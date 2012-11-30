#include "include/TriangleOscillator.h"

TriangleOscillator::TriangleOscillator( float frequency )
	: Oscillator::Oscillator( frequency ) {

}

TriangleOscillator::TriangleOscillator( int sampleRate, float frequency )
	: Oscillator::Oscillator( sampleRate, frequency ) {

}

float TriangleOscillator::nextSample() {
	float value = ( ( 1.0f / M_PI ) * m_currentPhase - 1.0f );
	if( value < 0.0f ) {
		value = -value;
	}

	value = 2.0f * ( value - 0.5f );
    //short sample = SHORT_MAX - ( SHORT_MAX + SHORT_MAX * value );

	m_currentPhase += m_phaseIncrement;
	if( m_currentPhase > 2.0f * M_PI ) {
		m_currentPhase = 0.0f;
	}

    return value;
}
