#include <iostream>
#include <math.h>
#include "WavWriter.h"

char * generateWave( int * length ) {
	int sampleRate = 44100;
	int frequency = 440;
	int samplesPerWave = sampleRate / frequency;
	int duration = 10;
	int samples = sampleRate * duration;
	float phaseIncrement = (float) ( 2.0 * 3.1416 ) / (float) samplesPerWave;
	char * wave = new char[samples];
	
	for( int i = 0; i < samples; i++ ) {
		wave[i] = (char) ( 127.0 * sin( i * phaseIncrement ) + 127.0 );
	}

	*length = samples;

	return wave;
}

int main() {
	std::string filename( "hello.wav" );
	WavWriter wavWriter( filename );

	wavWriter.setBitsPerSample( 8 );
	wavWriter.setStereo( false );

	int length = 0;
	char * data = generateWave( &length );
	
	if( wavWriter.writeWav( data, length ) ) {
		std::cout << "hooray! it worked!" << std::endl;
	} else {
		std::cout << "aww, no worky." << std::endl;
	}

	return 0;
}
