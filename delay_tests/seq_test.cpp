#include <iostream>
#include <jack/jack.h>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "JackSequencerController.h"
#include "Sequencer.h"
#include "Note.h"
#include <vector>
#include "Oscillator.h"
#include "SineOscillator.h"

int main( int argc, char ** argv ) {
	JackSequencerController controller;
	controller.init();
	int sampleRate = jack_get_sample_rate( controller.getClient() );
	Sequencer sequencer( sampleRate, 400 );
	sequencer.init();

	controller.setSequencer( &sequencer );

	std::vector<Note *> notes = sequencer.getNotes();

	std::vector<Note *>::iterator it;
	int i = 0;
	for( it = notes.begin(); it != notes.end(); it++ ) {
		(*it)->setBeat( i );
		i+=2;
	}

	controller.play();
	
	while( 1 ) {
		sleep( 1 );
	}
	
	return 0;
}
