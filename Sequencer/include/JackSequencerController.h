#ifndef JACKSEQUENCERCONTROLLER_H
#define JACKSEQUENCERCONTROLLER_H

#define jack_default_audio_sample_t sample_t

#include <jack/jack.h>
#include <QString>
#include "include/Sequencer.h"
#include "include/AbstractSequencerController.h"

class JackSequencerController : public AbstractSequencerController {
public:
    explicit JackSequencerController( Sequencer * sequencer );
    virtual void init();
    virtual void play();
    virtual void pause();
    virtual void stop();
    static int doProcess( jack_nframes_t nframes, void * args );
    jack_client_t * getClient();
    sample_t nextSample();

signals:
    void jackInitError( QString message );

private:
    jack_client_t * m_client;
    Sequencer * m_sequencer;
};

#endif // JACKSEQUENCERCONTROLLER_H
