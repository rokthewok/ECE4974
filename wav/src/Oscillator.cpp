#include "Oscillator.h"


Oscillator::Oscillator()
	: m_sampleRate( 44100 ),
	  m_frequency( 440.0f ),
	  m_currentPhase( 0.0f ) {
	m_phaseIncrement = (float) ( ( 2.0 * M_PI ) / ( (float) m_sampleRate / m_frequency ) );
}

Oscillator::Oscillator( float frequency ) 
	: m_sampleRate( 44100 ),
	  m_frequency( frequency ),
	  m_currentPhase( 0.0f ) {
	m_phaseIncrement = (float) ( ( 2.0 * M_PI ) / ( (float) m_sampleRate / m_frequency ) );
}

Oscillator::Oscillator( int sampleRate, float frequency )
	: m_sampleRate( sampleRate ),
	  m_frequency( frequency ),
	  m_currentPhase( 0.0f ) {
	m_phaseIncrement = (float) ( ( 2.0 * 3.1416 ) / ( (float) m_sampleRate / m_frequency ) );
}

Oscillator::~Oscillator() {

}

int Oscillator::getSampleRate() const {
	return m_sampleRate;
}

void Oscillator::setSampleRate( int sampleRate ) {
	m_sampleRate = sampleRate;

	m_currentPhase = 0.0f;
	m_phaseIncrement = (float) ( ( 2.0 * M_PI ) / ( (float) m_sampleRate / m_frequency ) );
}

float Oscillator::getFrequency() const {
	return m_frequency;
}

void Oscillator::setFrequency( float frequency ) {
	m_frequency = frequency;

	m_currentPhase = 0.0f;
	m_phaseIncrement = (float) ( ( 2.0 * M_PI ) / ( (float) m_sampleRate / m_frequency ) );
}
