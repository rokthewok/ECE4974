#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QCheckBox>
#include "Wavetype.h"
#include "WavDataBuilder.h"

class JackSequencerController;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow( JackSequencerController * sequencerController, QWidget *parent = 0 );
    ~MainWindow();
    
public slots:
    void setNoteOneBeats();
    void setNoteTwoBeats();
    void setNoteThreeBeats();
    void setNoteFourBeats();
    void setNoteFiveBeats();
    void setNoteSixBeats();

    void buttonOnePressed();
    void buttonTwoPressed();
    void buttonThreePressed();
    void buttonFourPressed();
    void buttonFivePressed();
    void buttonSixPressed();

    void amplitudeSliderChanged( int value );
    void frequencySpinnerChanged( double value );
    void harmonicitySpinnerChanged( double value );
    void waveformChooserChanged( QString wave );
    void modulationIndexSpinnerChanged( double value );

    void parametersChanged();

    void initError( QString message );
    void playError( QString message );

    void saveWav();
    void saveSuccess();
    void saveFailure();
    void chooseFilename();

private:
    void setComboBox( Wavetype wavetype );

    Ui::MainWindow *ui;
    JackSequencerController * m_sequencerController;
    QList<QCheckBox *> m_noteOneButtons;
    QList<QCheckBox *> m_noteTwoButtons;
    QList<QCheckBox *> m_noteThreeButtons;
    QList<QCheckBox *> m_noteFourButtons;
    QList<QCheckBox *> m_noteFiveButtons;
    QList<QCheckBox *> m_noteSixButtons;
    int m_currentNote;
    WavDataBuilder m_builder;

    const QString m_sine = "Sine";
    const QString m_fm = "FM";
    const QString m_rsaw = "Rising Sawtooth";
    const QString m_triangle = "Triangle";
};

#endif // MAINWINDOW_H
