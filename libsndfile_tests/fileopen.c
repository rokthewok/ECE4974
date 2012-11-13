#include <stdio.h>
#include <sndfile.h>

int main( int argc, char ** argv ) {
	SNDFILE * file;
	SF_INFO info;
	file = sf_open( argv[1], SFM_READ, &info );

	printf( "Sample rate: %d\nChannels: %d\nFormat: %d\nSections: %d\nSeekable: %d\n",
			info.samplerate, info.channels, info.format, info.sections, info.seekable );
	return 0;
}
