#ifndef JACKSEQUENCERCONTROLLER_H
#define JACKSEQUENCERCONTROLLER_H

#define sample_t jack_default_audio_sample_t

#include <jack/jack.h>
#include <QObject>
#include <QString>
#include "include/Sequencer.h"

class JackSequencerController : public QObject {
    Q_OBJECT
public:
    JackSequencerController();
    void init();
    static int doProcess( jack_nframes_t nframes, void * args );
    jack_client_t * getClient();
    jack_port_t * getPort();
    sample_t nextSample();
    Sequencer * getSequencer();
    void setSequencer( Sequencer * sequencer );

signals:
    void jackInitError( QString message );
    void jackPlayError( QString message );

public slots:
    void addNoteOnBeat( int note, int beat );
    void removeNoteOnBeat( int note, int beat );
    void play();
    void pause();
    void stop();

private:
    jack_client_t * m_client;
    jack_port_t * m_outgoingPort;
    const char * m_destinationPort;
    Sequencer * m_sequencer;
};

#endif // JACKSEQUENCERCONTROLLER_H
