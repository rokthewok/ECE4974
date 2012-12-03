#ifndef SEQUENCER_H
#define SEQUENCER_H

#include <QList>
#include "Note.h"

#define NUM_NOTES   5

class Sequencer {
public:
    explicit Sequencer( int sampleRate );
    Sequencer( int sampleRate, int bpm );
    float nextSample();
    int getCurrentRepeat() const;
    int getSampleRate() const;
    int getCurrentBeat() const;
    int getBpm() const;
    QList<Note *> getNotes();
    void setSampleRate();
    void setBpm();
    void pause();
    void stop();
private:
    int m_bpm;
    int m_beat;
    int m_sampleRate;
    int m_samplesPerBeat;
    int m_currentRepeat;
    QList<Note *> m_notes;
};

#endif // SEQUENCER_H
