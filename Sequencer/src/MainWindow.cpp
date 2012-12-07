#include "include/MainWindow.h"
#include "ui_mainwindow.h"
#include "include/JackSequencerController.h"

MainWindow::MainWindow(JackSequencerController *sequencerController, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_sequencerController( sequencerController )
{
    ui->setupUi(this);
    connect( ui->playButton, SIGNAL(clicked()), m_sequencerController, SLOT( play() ) );
    connect( ui->stopButton, SIGNAL( clicked() ), m_sequencerController, SLOT( stop() ) );

    for( int i = 0; i < m_sequencerController->getSequencer()->getBarLength(); i++ ) {
        // add a radio button to each list
        m_noteOneButtons.append( new QCheckBox() );
        m_noteTwoButtons.append( new QCheckBox() );
        m_noteThreeButtons.append(new QCheckBox() );
        m_noteFourButtons.append( new QCheckBox() );
        m_noteFiveButtons.append( new QCheckBox() );
        m_noteSixButtons.append( new QCheckBox() );

        // add to Gridlayout here
        ui->gridLayout->addWidget( m_noteOneButtons.at( i ), 5, i, Qt::AlignHCenter | Qt::AlignVCenter );
        ui->gridLayout->addWidget( m_noteTwoButtons.at( i ), 4, i, Qt::AlignHCenter | Qt::AlignVCenter );
        ui->gridLayout->addWidget( m_noteThreeButtons.at( i ), 3, i, Qt::AlignHCenter | Qt::AlignVCenter );
        ui->gridLayout->addWidget( m_noteFourButtons.at( i ), 2, i, Qt::AlignHCenter | Qt::AlignVCenter );
        ui->gridLayout->addWidget( m_noteFiveButtons.at( i ), 1, i, Qt::AlignHCenter | Qt::AlignVCenter );
        ui->gridLayout->addWidget( m_noteSixButtons.at( i ), 0, i, Qt::AlignHCenter | Qt::AlignVCenter );

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
