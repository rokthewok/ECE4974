#include "Note.h"
#include <stdlib.h>

Note::Note( float frequency, int sampleRate )
	: m_frequency( frequency ),
	  m_sampleRate( sampleRate ) {

}

Note::~Note() {

}
