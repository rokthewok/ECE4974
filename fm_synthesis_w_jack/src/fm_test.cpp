#include <iostream>
#include <jack/jack.h>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <string.h>
#include "WavWriter.h"
#include "FmOscillator.h"
#include "ByteConverter.h"

typedef jack_default_audio_sample_t sample_t;
Oscillator * osc;
jack_port_t * outputPort;

int process( jack_nframes_t nframes, void * args ) {
	sample_t * buffer = (sample_t *) jack_port_get_buffer( outputPort, nframes );
	
	jack_nframes_t i;
	for( i = 0; i < nframes; i++ ) {
		buffer[i] = osc->nextSample();
	}
	
	return 0;
}

int main( int argc, char ** argv ) {
	
	if( argc < 3 ) {
		std::cout << "please provide harmonicity and modulation index to command line!" << std::endl;
		return 0;
	}

	char * clientName = (char *) malloc( 9 * sizeof( char ) );
	strcpy( clientName, "fm" );

	jack_client_t * client;
	if( ( client = jack_client_open( clientName, JackNullOption, NULL ) ) == 0 ) {
		fprintf (stderr, "jack server not running?\n");
		return 1;
	}
	
	jack_set_process_callback( client, process, 0 );
	outputPort = jack_port_register( client, "Hz", JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput, 0 );

	int sampleRate = jack_get_sample_rate( client );
	float frequency = 440.0f;
	float harmonicity = atof( argv[1] );
	float modulationIndex = atof( argv[2] );

	Oscillator * osc = new FmOscillator( sampleRate, frequency, harmonicity, modulationIndex );

	if ( jack_activate( client ) ) {
		fprintf (stderr, "cannot activate client");
		return 1;
	}
	
	const char ** ports;
	if( ( ports = jack_get_ports( client, NULL, NULL, JackPortIsPhysical | JackPortIsInput ) ) == NULL ) {
		fprintf( stderr, "cannot get playback ports" );
		return 1;
	}
	
	int i = 0;
	while( ports[i] != NULL ) {
		if( !jack_connect( client, jack_port_name( outputPort ), ports[i] ) ) break;
	}
	
	sleep( 5000 );

	free( ports );
	delete osc;

	return 0;
}
