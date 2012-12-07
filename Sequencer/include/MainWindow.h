#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QCheckBox>

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

private:
    Ui::MainWindow *ui;
    JackSequencerController * m_sequencerController;
    QList<QCheckBox *> m_noteOneButtons;
    QList<QCheckBox *> m_noteTwoButtons;
    QList<QCheckBox *> m_noteThreeButtons;
    QList<QCheckBox *> m_noteFourButtons;
    QList<QCheckBox *> m_noteFiveButtons;
    QList<QCheckBox *> m_noteSixButtons;
};

#endif // MAINWINDOW_H
