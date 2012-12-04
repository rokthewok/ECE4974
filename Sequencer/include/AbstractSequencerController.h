#ifndef ABSTRACTSEQUENCERCONTROLLER_H
#define ABSTRACTSEQUENCERCONTROLLER_H

#include <QObject>

class AbstractSequencerController : public QObject {
    Q_OBJECT
public:
    virtual void init() = 0;
    virtual void play() = 0;
    virtual void stop() = 0;
    virtual void pause() = 0;
};

#endif // ABSTRACTSEQUENCERCONTROLLER_H
