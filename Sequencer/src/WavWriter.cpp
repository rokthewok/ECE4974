#include <iostream>
#include "include/ByteConverter.h"
#include "include/WavWriter.h"

WavWriter::WavWriter( std::string filename )
	: m_filename( filename ),
	  m_stereo( false ),
	  m_sampleRate( 44100 ),
	  m_format( PCM ),
	  m_bitsPerSample( 16 ) {

}

int WavWriter::getSampleRate() const {
	return m_sampleRate;
}

void WavWriter::setSampleRate( int sampleRate ) {
	m_sampleRate = sampleRate;
}

bool WavWriter::isStereo() const {
	return m_stereo;
}

void WavWriter::setStereo( bool yes ) {
	m_stereo = yes;
}

WavWriter::AudioFormat WavWriter::getAudioFormat() const {
	return m_format;
}

void WavWriter::setAudioFormat( AudioFormat format ) {
	m_format = format;
}

int WavWriter::getBitsPerSample() const {
	return m_bitsPerSample;
}

void WavWriter::setBitsPerSample( int bits ) {
	m_bitsPerSample = bits;
}

bool WavWriter::writeWav( char * wave, int length ) {
	if( isStereo() ) {
		return writeWav( wave, wave, length );
	}

	std::ofstream fout( m_filename.c_str(), std::ios::out | std::ios::binary );
	if( !fout.is_open() ) {
		return false;
	}

	if( !writeHeader( fout, length ) ) {
		return false;
	}

	char * intBuf = new char[4];
	// write chunk two size
	ByteConverter::intToBytes( length, intBuf );
	fout.write( intBuf, 4 );

	// write the data
	fout.write( wave, length );
	
	fout.flush();
	fout.close();

	delete [] intBuf;

	return true;
}

bool WavWriter::writeWav( char * left, char * right, int length ) {
	if( !isStereo() ) {
		return false;
	}
	
	std::ofstream fout( m_filename.c_str(), std::ios::out | std::ios::binary );
	if( !fout.is_open() ) {
		return false;
	}

	if( !writeHeader( fout, length * 2 ) ) {
		return false;
	}
	
	char * intBuf = new char[4];
	ByteConverter::intToBytes( length * 2, intBuf );
	fout.write( intBuf, 4 );

	// samples must alternate in stereo, with left channel samples first
	for( int i = 0; i < length; i++ ) {
		fout.put( left[i] );
		fout.put( right[i] );
	}
	
	delete [] intBuf;

	return true;
}

bool WavWriter::writeHeader( std::ofstream & fout, int length ) {
	char * intBuf = new char[4];
	char * shortBuf = new char[2];

	ByteConverter::intToBytes( 36 + length, intBuf );
	
	// write "RIFF"
	fout.write( ckId, 4 );
	// write total size of the chunks, less the 8 bytes for RIFF and WAVE
	fout.write( intBuf, 4 );
	// write "WAVE"
	fout.write( format, 4 );
	// write "fmt "
	fout.write( fmt_, 4 );

	ByteConverter::intToBytes( 16, intBuf );
	// write chunk one size
	fout.write( intBuf, 4 );

	// write the compression level
	if( m_format == PCM ) {
		ByteConverter::shortToBytes( 1, shortBuf );
		fout.write( shortBuf, 2 );
	} else {
		// support for other compression formats later
		return false;
	}

	if( isStereo() ) {
		ByteConverter::shortToBytes( 2, shortBuf );
		fout.write( shortBuf, 2 );
	} else {
		// mono
		ByteConverter::shortToBytes( 1, shortBuf );
		fout.write( shortBuf, 2 );
	}

	ByteConverter::intToBytes( m_sampleRate, intBuf );
	// write the sample rate
	fout.write( intBuf, 4 );
	
	int channels = 1;
	if( isStereo() ) channels = 2;

	// write byteRate
	int byteRate = m_sampleRate * channels * ( m_bitsPerSample / 8 );
	ByteConverter::intToBytes( byteRate, intBuf );
	fout.write( intBuf, 4 );

	// write block align
	short blockAlign = channels * ( m_bitsPerSample / 8 );
	ByteConverter::shortToBytes( blockAlign, shortBuf );
	fout.write( shortBuf, 2 );

	// write bits per sample
	ByteConverter::shortToBytes( (short) m_bitsPerSample, shortBuf );
	fout.write( shortBuf, 2 );

	// write "data"
	fout.write( data, 4 );

	delete [] intBuf;
	delete [] shortBuf;

	return true;
}

char * WavWriter::ckId = "RIFF"; 
char * WavWriter::format = "WAVE";
char * WavWriter::fmt_ = "fmt ";
char * WavWriter::data = "data";
