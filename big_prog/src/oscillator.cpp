#include "Oscillator.h"
#include <Math.h>

Oscillator::Oscillator()
	: m_sampleRate( 44100 ),
	  m_frequency( 440.0f ),
	  m_currentPhase( 0.0f ),
	  m_phaseIncrement( 0.0f ) {
	m_phaseIncrement = ( 2.0f * M_PI ) / m_frequency;
}

Oscillator::Oscillator( int sampleRate, float frequency )
	: m_sampleRate( sampleRate ),
	  m_frequency( frequency ),
	  m_currentPhase( 0.0f ),
	  m_phaseIncrement( 0.0f ) {
	m_sampleRate = m_sampleRate < 0 ? -m_sampleRate : m_sampleRate;
	m_frequency = m_frequency < 0 ? -m_frequency : m_frequency;
	m_phaseIncrement = ( 2.0f * M_PI ) / m_frequency;
}

int Oscillator::getSampleRate() const {
	return m_sampleRate;
}

float Oscillator::getFrequency() const {
	return m_frequency;
}

float Oscillator::getCurrentPhase() const {
	return m_currentPhase;
}
