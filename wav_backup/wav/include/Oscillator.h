#ifndef OSCILLATOR_H
#define OSCILLATOR_H

#define SHORT_MAX 32767
#define M_PI 3.1416
class Oscillator {
public:
	Oscillator();
	explicit Oscillator( float frequency );
	Oscillator( int sampleRate, float frequency );
	~Oscillator();
	virtual short nextSample() = 0;
	int getSampleRate() const;
	void setSampleRate( int sampleRate );
	float getFrequency() const;
	void setFrequency( float frequency );
protected:
	float m_currentPhase;
	float m_phaseIncrement;
private:
	int m_sampleRate;
	float m_frequency;
};

#endif // OSCILLATOR_H
