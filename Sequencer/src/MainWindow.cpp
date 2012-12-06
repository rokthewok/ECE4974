#include "include/MainWindow.h"
#include "ui_mainwindow.h"
#include "include/JackSequencerController.h"

MainWindow::MainWindow(JackSequencerController *sequencerController, QWidget *parent) :
    m_sequencerController( sequencerController ),
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect( ui->playButton, SIGNAL(clicked()), m_sequencerController, SLOT( play() ) );
    connect( ui->stopButton, SIGNAL( clicked() ), m_sequencerController, SLOT( stop() ) );
}

MainWindow::~MainWindow()
{
    delete ui;
}
