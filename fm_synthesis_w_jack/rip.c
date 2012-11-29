#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <jack/jack.h>

typedef jack_default_audio_sample_t sample_t;

jack_port_t * outputPort;
int offset = 0;
int offsetTwo = 0;

int process( jack_nframes_t nframes, void * args ) {
	sample_t * buffer = (sample_t *) jack_port_get_buffer( outputPort, nframes );
	
	jack_nframes_t i;
	for( i = 0; i < nframes; i++ ) {
		buffer[i] = wave[offset];
		offset++;
		if( offset == tableSize ) offset = 0;
	}
	
	return 0;
}

int main( int argc, char ** argv ) {
	char * clientName = (char *) malloc( 9 * sizeof( char ) );
	strcpy( clientName, "sine1" );
	float frequency = 440.0f;

	jack_client_t * client;
	if( ( client = jack_client_open( clientName, JackNullOption, NULL ) ) == 0 ) {
		fprintf (stderr, "jack server not running?\n");
		return 1;
	}
	
	jack_set_process_callback( client, process, 0 );
	outputPort = jack_port_register( client, "Hz", JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput, 0 );

	int sampleRate = jack_get_sample_rate( client );

	if ( jack_activate( client ) ) {
		fprintf (stderr, "cannot activate client");
		return 1;
	}
	
	while (1) {
		sleep(1);
	}

	return 0;
}

jack_client_open
jack_set_process_callback
jack_port_register
jack_get_sample_rate
jack_activate
jack_connect
