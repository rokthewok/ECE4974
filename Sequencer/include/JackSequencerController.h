#ifndef JACKSEQUENCERCONTROLLER_H
#define JACKSEQUENCERCONTROLLER_H

#define jack_default_audio_sample_t sample_t

#include <jack/jack.h>
#include <QObject>
#include <QString>
#include "include/Sequencer.h"

class JackSequencerController : public QObject {
    Q_OBJECT
public:
    explicit JackSequencerController( Sequencer * sequencer );
    void init();
    void play();
    void pause();
    void stop();
    static int doProcess( jack_nframes_t nframes, void * args );
    jack_client_t * getClient();
    jack_port_t * getPort();
    sample_t nextSample();

signals:
    void jackInitError( QString message );

public slots:
    void addNoteOnBeat( int note, int beat );

private:
    jack_client_t * m_client;
    jack_port_t * m_port;
    Sequencer * m_sequencer;
};

#endif // JACKSEQUENCERCONTROLLER_H
