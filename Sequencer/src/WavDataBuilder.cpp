#include "include/WavDataBuilder.h"
#include "include/ByteConverter.h"
#include "include/WavWriter.h"

WavDataBuilder::WavDataBuilder()
    : QObject::QObject( 0 ) {

}

void WavDataBuilder::buildAndSaveWav( Sequencer  & sequencer, int numberOfRepeats, QString filename ) {
    WavWriter wavWriter( filename.toStdString() );
    wavWriter.setSampleRate( sequencer.getSampleRate() );
    sequencer.stop();

    int dataLength = 2 * (int) ( (float) sequencer.getSampleRate() / (float) sequencer.getBpm() ) *
            60 * sequencer.getBarLength() * numberOfRepeats;

    char * data = new char[dataLength];

    for( int i = 0; i < dataLength; i += 2 ) {
        ByteConverter::shortToBytes( (short) ( sequencer.nextSample() * SHORT_MAX ), data, i );
    }

    wavWriter.setStereo( false );

    if( !wavWriter.writeWav( data, dataLength ) ) {
        writeFailed();
    } else {
        writeSucceeded();
    }
}
