#ifndef OSCILLATOR_H
#define OSCILLATOR_H

class Oscillator {
	public:
		Oscillator();
		Oscillator( int sampleRate, float frequency );
		~Oscillator();
		int getSampleRate() const;
		float getFrequency() const;
		float getCurrentPhase() const;
		void setSampleRate( int sampleRate );
		void setFrequency( float frequency );
	private:
		int m_sampleRate;
		float m_frequency;
		float m_phaseIncrement;
		float m_currentPhase;
};

#endif // OSCILLATOR_H
