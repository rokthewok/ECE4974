#ifndef SEQUENCER_H
#define SEQUENCER_H

#include <QList>
#include "Note.h"

#define NUM_NOTES   5

class Sequencer {
public:
    explicit Sequencer( int sampleRate );
    Sequencer( int sampleRate, int bpm );
    void init();
    float nextSample();
    int getCurrentRepeat() const;
    int getSampleRate() const;
    int getCurrentBeat() const;
    int getBpm() const;
    QList<Note *> & getNotes();
    int getBarLength() const;
    void setSampleRate( int sampleRate );
    void setBpm(int bpm);
    void stop();
    bool setNoteOnBeat( int note, int beat );
    bool removeNoteOnBeat( int note, int beat );
    void setOscillator( int note, Oscillator * oscillator, Wavetype wavetype );

private:
    int m_bpm;
    int m_beat;
    int m_barLength;
    int m_currentSample;
    float m_decay;
    int m_sampleRate;
    int m_samplesPerBeat;
    int m_currentRepeat;
    QList<Note *> m_notes;
    QList<int> m_numberOfNotesPerBeat;

    int calculateSamplesPerBeat( int sampleRate, int bpm );
};

#endif // SEQUENCER_H
