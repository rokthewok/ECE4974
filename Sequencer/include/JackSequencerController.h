#ifndef JACKSEQUENCERCONTROLLER_H
#define JACKSEQUENCERCONTROLLER_H

#include "include/AbstractSequencerController.h"

class JackSequencerController : public AbstractSequencerController {
public:
    explicit JackSequencerController( Sequencer * sequencer );
    virtual void init();
    virtual void play();
    virtual void pause();
    virtual void stop();
private:
};

#endif // JACKSEQUENCERCONTROLLER_H
