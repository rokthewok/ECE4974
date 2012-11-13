#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <jack/jack.h>

typedef jack_default_audio_sample_t sample_t;

sample_t * wave;
sample_t * waveTwo;
jack_port_t * outputPort;
jack_port_t * outputPortTwo;
int tableSize, tableSizeTwo;
int offset = 0;
int offsetTwo = 0;

int processTwo( jack_nframes_t nframes, void * args ) {
	sample_t * buffer = (sample_t *) jack_port_get_buffer( outputPortTwo, nframes );
	
	jack_nframes_t i;
	for( i = 0; i < nframes; i++ ) {
		buffer[i] = waveTwo[offsetTwo];
		offsetTwo++;
		if( offsetTwo == tableSizeTwo ) offsetTwo = 0;
	}
	
	return 0;
}

int process( jack_nframes_t nframes, void * args ) {
	sample_t * buffer = (sample_t *) jack_port_get_buffer( outputPort, nframes );
	
	jack_nframes_t i;
	for( i = 0; i < nframes; i++ ) {
		if( i % 2 == 0 ) {
			buffer[i] = wave[offset];
		} else {
			buffer[i] = waveTwo[offsetTwo];
		}
		//buffer[i] = wave[offset];
		offset++;
		offsetTwo++;
		if( offset == tableSize ) offset = 0;
		if( offsetTwo == tableSizeTwo ) offsetTwo = 0;
	}
	
	return 0;
}

int main( int argc, char ** argv ) {
	char * clientName = (char *) malloc( 9 * sizeof( char ) );
	strcpy( clientName, "sine1" );
	float frequency = 440.0f;
	
	char * clientNameTwo = (char *) malloc( 9 * sizeof( char ) );
	strcpy( clientNameTwo, "sine2" );

	jack_client_t * client;
	jack_client_t * clientTwo;
	if( ( client = jack_client_open( clientName, JackNullOption, NULL ) ) == 0 ) {
		fprintf (stderr, "jack server not running?\n");
		return 1;
	}

	if( ( clientTwo = jack_client_open( clientNameTwo, JackNullOption, NULL ) ) == 0 ) {
		fprintf (stderr, "jack server not running?\n");
		return 1;
	}
	
	//jack_set_process_callback( clientTwo, processTwo, 0 );
	jack_set_process_callback( client, process, 0 );
	outputPort = jack_port_register( client, "Hz", JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput, 0 );
	//outputPortTwo = jack_port_register( clientTwo, "Hz", JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput, 0 );	

	int sampleRate = jack_get_sample_rate( client );
	int sampleRateTwo = jack_get_sample_rate( clientTwo );
	int frequencyTwo = 523.25;
	tableSize = sampleRate / frequency;
	tableSizeTwo = sampleRateTwo / frequencyTwo;
	float phaseIncrementTwo = ( 2 * M_PI ) / (float) tableSizeTwo;

	waveTwo = ( sample_t * ) malloc( tableSizeTwo * sizeof( sample_t ) );
	
	int j;
	for( j = 0; j < tableSizeTwo; j++ ) {
		waveTwo[j] = 0.75 * sin( j * phaseIncrementTwo );
	}

	wave = (sample_t *) malloc( tableSize * sizeof( sample_t ) );
	float phaseIncrement = ( 2 * M_PI ) / (float) tableSize;
	int i;
	for( i = 0; i < tableSize; i++ ) {
		wave[i] = 0.75 * sin( i * phaseIncrement );
	}

	if ( jack_activate( client ) ) {
		fprintf (stderr, "cannot activate client");
		return 1;
	}
 	
	//if( jack_activate( clientTwo ) ) {
	//	fprintf( stderr, "cannot activate client" );
	//	return 1;
	//}
	while (1) {
		sleep(1);
	}

	return 0;
}
