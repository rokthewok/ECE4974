#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string>
#include "WavWriter.h"
#include "FmOscillator.h"
#include "ByteConverter.h"

int main( int argc, char ** argv ) {
	
	if( argc < 4 ) {
		std::cout << "please provide a filename, harmonicity, and modulation index to command line!" << std::endl;
		return 0;
	}

	int sampleRate = 44100;
	float frequency = 440.0f;
	float harmonicity = atof( argv[2] );
	float modulationIndex = atof( argv[3] );
	
	std::string filename = "res/";
	filename += argv[1];
	WavWriter writer( filename  );
	Oscillator * osc = new FmOscillator( sampleRate, frequency, harmonicity, modulationIndex );

	writer.setBitsPerSample( 16 );
	writer.setStereo( false );
	
	int dataSize = 5 * osc->getSampleRate() * 2; // duration in seconds * sample rate * bytes per sample
	char * data = new char[dataSize];

	// write samples into byte array
	for( int i = 0; i < dataSize; i += 2 ) {
		ByteConverter::shortToBytes( osc->nextSample(), data, i );
	}

	if( writer.writeWav( data, dataSize ) ) {
		std::cout << "Great success!" << std::endl;
	} else {
		std::cout << "Ohhhh womp :(" << std::endl;
	}

	delete osc;
	delete [] data;

	return 0;
}
