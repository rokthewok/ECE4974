#ifndef NOTE_H
#define NOTE_H
#include <jack/jack.h>

typedef jack_default_sample_t sample_t;

class Note {
public:
	Note( float frequency, int sampleRate );
	~Note();
	int getTableLength() const;
	sample_t * getTable();
private:
	float m_frequency;
	int m_sampleRate;
	int m_tableLength;
	sample_t * wave;
};

#endif // NOTE_H
