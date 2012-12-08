#ifndef WAVDATABUILDER_H
#define WAVDATABUILDER_H

#include <QObject>
#include "Sequencer.h"

class WavDataBuilder : public QObject {
        Q_OBJECT
public:
    WavDataBuilder();
public slots:
    void buildData( Sequencer sequencer, int numberOfRepeats );
};

#endif // WAVDATABUILDER_H
