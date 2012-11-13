#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include "WavWriter.h"
#include "ByteConverter.h"
#include "SineOscillator.h"
#include "TriangleOscillator.h"
#include "RisingSawtoothOscillator.h"

int main( int argc, char ** argv ) {
	if( argc <= 2 ) {
		std::cout << "please provide valid command line arguments. Syntax is '/wav_writer <filename.wav> <oscillatortype>'" << std::endl;
		return -1;

	}

	std::string filename;
	filename = "res/";
	filename += argv[1];

	Oscillator * oscillator;
	Oscillator * oscillatorTwo = 0;

	if( strcmp( argv[2], "triangle" ) == 0 ) {
		oscillator = new TriangleOscillator();
	} else if( strcmp( argv[2], "rsaw" ) == 0 ) {
		oscillator = new RisingSawtoothOscillator();
	} else if( strcmp( argv[2], "additive" ) == 0 ) {
		oscillator = new SineOscillator();
		oscillatorTwo = new SineOscillator( 523.0f );
	} else {
		oscillator = new SineOscillator();
	}

	WavWriter wavWriter( filename );

	wavWriter.setBitsPerSample( 16 );
	wavWriter.setStereo( false );
	
	int dataSize = 5 * oscillator->getSampleRate() * 2; // duration in seconds * sample rate * bytes per sample
	char * data = new char[dataSize];
	
	if( oscillatorTwo != 0 ) {
		for( int i = 0; i < dataSize - 1; i+=2 ) {
			ByteConverter::shortToBytes( oscillator->nextSample() / 2 + oscillatorTwo->nextSample() / 2, data, i );
		}
	} else {
		for( int i = 0; i < dataSize - 1; i+=2 ) {
			ByteConverter::shortToBytes( oscillator->nextSample(), data, i );
		}
	}

	if( wavWriter.writeWav( data, dataSize ) ) {
		std::cout << "hooray! it worked!" << std::endl;
	} else {
		std::cout << "aww, no worky." << std::endl;
	}

	delete oscillator;
	if( oscillatorTwo != 0 ) {
		delete oscillatorTwo;
	}

	return 0;
}
