#include <QComboBox>
#include "include/MainWindow.h"
#include "ui_mainwindow.h"
#include "include/JackSequencerController.h"
#include "include/Oscillator.h"
#include "include/Note.h"
#include "include/FmOscillator.h"

MainWindow::MainWindow(JackSequencerController *sequencerController, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_sequencerController( sequencerController )
{
    ui->setupUi(this);
    connect( ui->playButton, SIGNAL(clicked()), m_sequencerController, SLOT( play() ) );
    connect( ui->stopButton, SIGNAL( clicked() ), m_sequencerController, SLOT( stop() ) );
    setFixedSize( 600, 400 );

    ui->tabWidget->setTabText( 0, QString( "Sequencer" ) );
    ui->tabWidget->setTabText( 1, QString( "Note Editor" ) );

    QComboBox * comboBox = ui->waveformChooser;
    comboBox->addItem( m_sine );
    comboBox->addItem( m_triangle );
    comboBox->addItem( m_rsaw );
    comboBox->addItem( m_fm );

    connect( ui->noteOneButton, SIGNAL( clicked() ), this, SLOT( buttonOnePressed() ) );
    connect( ui->noteTwoButton, SIGNAL( clicked() ), this, SLOT( buttonTwoPressed() ) );
    connect( ui->noteThreeButton, SIGNAL( clicked() ), this, SLOT( buttonThreePressed() ) );
    connect( ui->noteFourButton, SIGNAL( clicked() ), this, SLOT( buttonFourPressed() ) );
    connect( ui->noteFiveButton, SIGNAL( clicked() ), this, SLOT( buttonFivePressed() ) );
    connect( ui->noteSixButton, SIGNAL( clicked() ), this, SLOT( buttonSixPressed() ) );

    connect( ui->amplitudeSlider, SIGNAL( sliderMoved(int) ), this, SLOT( amplitudeSliderChanged(int) ) );
    connect( ui->frequencySpinner, SIGNAL( valueChanged(double) ), this, SLOT( frequencySpinnerChanged(double) ) );
    connect( ui->modIndexSpinner, SIGNAL( valueChanged(double) ), this, SLOT( modulationIndexSpinnerChanged(double) ) );
    connect( ui->harmonicitySpinner, SIGNAL( valueChanged(double) ), this, SLOT( harmonicitySpinnerChanged(double) ) );
    connect( ui->waveformChooser, SIGNAL( currentIndexChanged(QString) ), this, SLOT( waveformChooserChanged(QString) ) );

    for( int i = 0; i < m_sequencerController->getSequencer()->getBarLength(); i++ ) {
        // add a radio button to each list
        m_noteOneButtons.append( new QCheckBox() );
        m_noteTwoButtons.append( new QCheckBox() );
        m_noteThreeButtons.append(new QCheckBox() );
        m_noteFourButtons.append( new QCheckBox() );
        m_noteFiveButtons.append( new QCheckBox() );
        m_noteSixButtons.append( new QCheckBox() );

        // add to Gridlayout here
        ui->sequencerLayout->addWidget( m_noteOneButtons.at( i ), 5, i, Qt::AlignHCenter | Qt::AlignVCenter );
        ui->sequencerLayout->addWidget( m_noteTwoButtons.at( i ), 4, i, Qt::AlignHCenter | Qt::AlignVCenter );
        ui->sequencerLayout->addWidget( m_noteThreeButtons.at( i ), 3, i, Qt::AlignHCenter | Qt::AlignVCenter );
        ui->sequencerLayout->addWidget( m_noteFourButtons.at( i ), 2, i, Qt::AlignHCenter | Qt::AlignVCenter );
        ui->sequencerLayout->addWidget( m_noteFiveButtons.at( i ), 1, i, Qt::AlignHCenter | Qt::AlignVCenter );
        ui->sequencerLayout->addWidget( m_noteSixButtons.at( i ), 0, i, Qt::AlignHCenter | Qt::AlignVCenter );

        // connect up radio buttons to appropriate slot
        connect( m_noteOneButtons.at( i ), SIGNAL( clicked() ), this, SLOT( setNoteOneBeats() ) );
        connect( m_noteTwoButtons.at( i ), SIGNAL( clicked() ), this, SLOT( setNoteTwoBeats() ) );
        connect( m_noteThreeButtons.at( i ), SIGNAL( clicked() ), this, SLOT( setNoteThreeBeats() ) );
        connect( m_noteFourButtons.at( i ), SIGNAL( clicked() ), this, SLOT( setNoteFourBeats() ) );
        connect( m_noteFiveButtons.at( i ), SIGNAL( clicked() ), this, SLOT( setNoteFiveBeats() ) );
        connect( m_noteSixButtons.at( i ), SIGNAL( clicked() ), this, SLOT( setNoteSixBeats() ) );
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setNoteOneBeats() {
    for( int i = 0; i < m_noteOneButtons.length(); i++ ) {
        if( m_noteOneButtons.at( i )->isChecked() ) {
            m_sequencerController->addNoteOnBeat( 0, i );
        } else {
            m_sequencerController->removeNoteOnBeat( 0, i );
        }
    }
}

void MainWindow::setNoteTwoBeats() {
    for( int i = 0; i < m_noteTwoButtons.length(); i++ ) {
        if( m_noteTwoButtons.at( i )->isChecked() ) {
            m_sequencerController->addNoteOnBeat( 1, i );
        } else {
            m_sequencerController->removeNoteOnBeat( 1, i );
        }
    }
}

void MainWindow::setNoteThreeBeats() {
    for( int i = 0; i < m_noteThreeButtons.length(); i++ ) {
        if( m_noteThreeButtons.at( i )->isChecked() ) {
            m_sequencerController->addNoteOnBeat( 2, i );
        } else {
            m_sequencerController->removeNoteOnBeat( 2, i );
        }
    }
}

void MainWindow::setNoteFourBeats() {
    for( int i = 0; i < m_noteFourButtons.length(); i++ ) {
        if( m_noteFourButtons.at( i )->isChecked() ) {
            m_sequencerController->addNoteOnBeat( 3, i );
        } else {
            m_sequencerController->removeNoteOnBeat( 3, i );
        }
    }
}

void MainWindow::setNoteFiveBeats() {
    for( int i = 0; i < m_noteFiveButtons.length(); i++ ) {
        if( m_noteFiveButtons.at( i )->isChecked() ) {
            m_sequencerController->addNoteOnBeat( 4, i );
        } else {
            m_sequencerController->removeNoteOnBeat( 4, i );
        }
    }
}

void MainWindow::setNoteSixBeats() {
    for( int i = 0; i < m_noteSixButtons.length(); i++ ) {
        if( m_noteSixButtons.at( i )->isChecked() ) {
            m_sequencerController->addNoteOnBeat( 5, i );
        } else {
            m_sequencerController->removeNoteOnBeat( 5, i );
        }
    }
}

void MainWindow::buttonOnePressed() {
    m_currentNote = 0;
    Note * note = m_sequencerController->getSequencer()->getNotes().at( 0 );
    Oscillator * oscillator = note->getOscillator();

    float frequency = oscillator->getFrequency();
    float amplitude = note->getAmplitude();

    blockSignals( true );
    if( note->getWavetype() == FM ) {
        FmOscillator * fm = static_cast<FmOscillator *>( oscillator );
        ui->harmonicitySpinner->setEnabled( true );
        ui->modIndexSpinner->setEnabled( true );
        ui->harmonicitySpinner->setValue( fm->getHarmonicity() );
        ui->modIndexSpinner->setValue( fm->getModulationIndex() );
    } else {
        ui->harmonicitySpinner->setEnabled( false );
        ui->modIndexSpinner->setEnabled( false );
    }

    ui->frequencySpinner->setValue( frequency );
    ui->amplitudeSlider->setValue( amplitude * 100.0f );

    setComboBox( note->getWavetype() );
    blockSignals( false );
}

void MainWindow::buttonTwoPressed() {
    m_currentNote = 1;
    Note * note = m_sequencerController->getSequencer()->getNotes().at( 1 );
    Oscillator * oscillator = note->getOscillator();

    float frequency = oscillator->getFrequency();
    float amplitude = note->getAmplitude();

    blockSignals( true );
    if( note->getWavetype() == FM ) {
        FmOscillator * fm = static_cast<FmOscillator *>( oscillator );
        ui->harmonicitySpinner->setEnabled( true );
        ui->modIndexSpinner->setEnabled( true );
        ui->harmonicitySpinner->setValue( fm->getHarmonicity() );
        ui->modIndexSpinner->setValue( fm->getModulationIndex() );
    } else {
        ui->harmonicitySpinner->setEnabled( false );
        ui->modIndexSpinner->setEnabled( false );
    }

    ui->frequencySpinner->setValue( frequency );
    ui->amplitudeSlider->setValue( amplitude * 100.0f );

    setComboBox( note->getWavetype() );
    blockSignals( false );
}

void MainWindow::buttonThreePressed() {
    m_currentNote = 2;
    Note * note = m_sequencerController->getSequencer()->getNotes().at( 2 );
    Oscillator * oscillator = note->getOscillator();

    float frequency = oscillator->getFrequency();
    float amplitude = note->getAmplitude();

    blockSignals( true );
    if( note->getWavetype() == FM ) {
        FmOscillator * fm = static_cast<FmOscillator *>( oscillator );
        ui->harmonicitySpinner->setEnabled( true );
        ui->modIndexSpinner->setEnabled( true );
        ui->harmonicitySpinner->setValue( fm->getHarmonicity() );
        ui->modIndexSpinner->setValue( fm->getModulationIndex() );
    } else {
        ui->harmonicitySpinner->setEnabled( false );
        ui->modIndexSpinner->setEnabled( false );
    }

    ui->frequencySpinner->setValue( frequency );
    ui->amplitudeSlider->setValue( amplitude * 100.0f );

    setComboBox( note->getWavetype() );
    blockSignals( false );
}

void MainWindow::buttonFourPressed() {
    m_currentNote = 3;
    Note * note = m_sequencerController->getSequencer()->getNotes().at( 3 );
    Oscillator * oscillator = note->getOscillator();

    float frequency = oscillator->getFrequency();
    float amplitude = note->getAmplitude();

    blockSignals( true );
    if( note->getWavetype() == FM ) {
        FmOscillator * fm = static_cast<FmOscillator *>( oscillator );
        ui->harmonicitySpinner->setEnabled( true );
        ui->modIndexSpinner->setEnabled( true );
        ui->harmonicitySpinner->setValue( fm->getHarmonicity() );
        ui->modIndexSpinner->setValue( fm->getModulationIndex() );
    } else {
        ui->harmonicitySpinner->setEnabled( false );
        ui->modIndexSpinner->setEnabled( false );
    }

    ui->frequencySpinner->setValue( frequency );
    ui->amplitudeSlider->setValue( amplitude * 100.0f );

    setComboBox( note->getWavetype() );
    blockSignals( false );
}

void MainWindow::buttonFivePressed() {
    m_currentNote = 4;
    Note * note = m_sequencerController->getSequencer()->getNotes().at( 4 );
    Oscillator * oscillator = note->getOscillator();

    float frequency = oscillator->getFrequency();
    float amplitude = note->getAmplitude();

    blockSignals( true );
    if( note->getWavetype() == FM ) {
        FmOscillator * fm = static_cast<FmOscillator *>( oscillator );
        ui->harmonicitySpinner->setEnabled( true );
        ui->modIndexSpinner->setEnabled( true );
        ui->harmonicitySpinner->setValue( fm->getHarmonicity() );
        ui->modIndexSpinner->setValue( fm->getModulationIndex() );
    } else {
        ui->harmonicitySpinner->setEnabled( false );
        ui->modIndexSpinner->setEnabled( false );
    }

    ui->frequencySpinner->setValue( frequency );
    ui->amplitudeSlider->setValue( amplitude * 100.0f );

    setComboBox( note->getWavetype() );
    blockSignals( false );
}

void MainWindow::buttonSixPressed() {
    m_currentNote = 5;
    Note * note = m_sequencerController->getSequencer()->getNotes().at( 5 );
    Oscillator * oscillator = note->getOscillator();

    float frequency = oscillator->getFrequency();
    float amplitude = note->getAmplitude();

    blockSignals( true );
    if( note->getWavetype() == FM ) {
        FmOscillator * fm = static_cast<FmOscillator *>( oscillator );
        ui->harmonicitySpinner->setEnabled( true );
        ui->modIndexSpinner->setEnabled( true );
        ui->harmonicitySpinner->setValue( fm->getHarmonicity() );
        ui->modIndexSpinner->setValue( fm->getModulationIndex() );
    } else {
        ui->harmonicitySpinner->setEnabled( false );
        ui->modIndexSpinner->setEnabled( false );
    }

    ui->frequencySpinner->setValue( frequency );
    ui->amplitudeSlider->setValue( amplitude * 100.0f );

    setComboBox( note->getWavetype() );
    blockSignals( false );
}

void MainWindow::setComboBox( Wavetype wavetype ) {
    if( wavetype == SINE ) {
        ui->waveformChooser->setCurrentIndex( ui->waveformChooser->findText( m_sine ) );
    } else if( wavetype == TRIANGLE ) {
        ui->waveformChooser->setCurrentIndex( ui->waveformChooser->findText( m_triangle ) );
    } else if( wavetype == FM ) {
        ui->waveformChooser->setCurrentIndex( ui->waveformChooser->findText( m_fm ) );
    } else if( wavetype == RSAW ) {
        ui->waveformChooser->setCurrentIndex( ui->waveformChooser->findText( m_rsaw ) );
    } else {
        ui->waveformChooser->setCurrentIndex( ui->waveformChooser->findText( m_sine ) );
    }
}

void MainWindow::amplitudeSliderChanged(int value) {
    m_sequencerController->setAmplitude( m_currentNote, (float) value / 100.0f );
}

void MainWindow::frequencySpinnerChanged(double value) {
    m_sequencerController->setFrequency( m_currentNote, (float) value );
}

void MainWindow::harmonicitySpinnerChanged(double value) {
    m_sequencerController->setHarmonicity( m_currentNote, (float) value );
}

void MainWindow::modulationIndexSpinnerChanged(double value) {
    m_sequencerController->setModulationIndex( m_currentNote, (float) value );
}

void MainWindow::waveformChooserChanged( QString wave ) {
    // TODO implement
}
