#include <iostream>
#include <jack/jack.h>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "Oscillator.h"
#include "SineOscillator.h"
#include "FmOscillator.h"

int main( int argc, char ** argv ) {
	JackSequencerController controller;
	controller.init();
	int sampleRate = jack_get_sample_rate( controller.getClient() );
	Sequencer sequencer( controller.getClient(), 100 );

	controller.setSequencer( &sequencer );

	return 0;
}
