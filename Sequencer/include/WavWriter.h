#ifndef WAVWRITER_H
#define WAVWRITER_H
#include <string>
#include <fstream>

class WavWriter {
public:
	typedef enum {
		PCM
	} AudioFormat;
	explicit WavWriter( std::string filename );
	int getSampleRate() const;
	void setSampleRate( int sampleRate );
	bool isStereo() const;
	void setStereo( bool yes );
	AudioFormat getAudioFormat() const;
	void setAudioFormat( AudioFormat format );
	int getBitsPerSample() const;
	void setBitsPerSample( int bits );

	bool writeWav( char * data, int length );
	bool writeWav( char * left, char * right, int length );
private:
	bool writeHeader( std::ofstream & fout, int length );
	
	std::string m_filename;
	bool m_stereo;
	int m_sampleRate;
	AudioFormat m_format;
	int m_bitsPerSample;

	static char * ckId;
	static char * format;
	static char * fmt_;
	static char * data;
};

#endif // WAVWRITER_H
