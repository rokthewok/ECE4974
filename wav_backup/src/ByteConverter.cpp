#include "ByteConverter.h"

void ByteConverter::shortToBytes( short value, char * buffer ) {
/* Writes a short in byte array format, big endian */
	buffer[0] = value & 0xFF;
	buffer[1] = ( value >> 8 ) & 0xFF;
}

void ByteConverter::shortsToBytes( short * values, int length, char * buffer ) {
	for( int i = 0, j = 0; i < length; i++, j += 2 ) {
		buffer[j] = values[i] & 0xFF;
		buffer[j + 1] = ( values[i] >> 8 ) & 0xFF;
	}
}

void ByteConverter::intToBytes( int value, char * buffer ) {
/* Writes an int in byte array format, big endian */
	buffer[0] = value & 0xFF;
	buffer[1] = ( value >> 8 ) & 0xFF;
	buffer[2] = ( value >> 16 ) & 0xFF;
	buffer[3] = ( value >> 24 ) & 0xFF;
}
