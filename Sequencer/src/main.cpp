#include <QtGui/QApplication>
#include <QList>
#include <jack/jack.h>
#include "include/MainWindow.h"
#include "include/JackSequencerController.h"
#include "include/Sequencer.h"
#include "include/Note.h"

int main(int argc, char *argv[])
{
    JackSequencerController controller;
    controller.init();

    Sequencer sequencer( jack_get_sample_rate( controller.getClient() ), 80 * 4 );
    sequencer.init();

    controller.setSequencer( &sequencer );

    QApplication a(argc, argv);
    MainWindow w( &controller );
    w.show();
    
    return a.exec();
}
