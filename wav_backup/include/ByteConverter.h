#ifndef BYTECONVERTER_H
#define BYTECONVERTER_H

class ByteConverter {
public:
	static void shortToBytes( short value, char * buffer );
	static void shortsToBytes( short * values, int length, char * buffer );
	static void intToBytes( int value, char * buffer );
};

#endif // BYTECONVERTER_H
