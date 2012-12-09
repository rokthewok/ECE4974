#ifndef WAVDATABUILDER_H
#define WAVDATABUILDER_H

#include <QObject>
#include "Sequencer.h"

#define SHORT_MAX   32767

class WavDataBuilder : public QObject {
        Q_OBJECT
public:
    WavDataBuilder();
signals:
    void writeFailed();
    void writeSucceeded();
public slots:
    void buildAndSaveWav( Sequencer & sequencer, int numberOfRepeats, QString filename );
};

#endif // WAVDATABUILDER_H
