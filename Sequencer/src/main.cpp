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

    QList<Note *> notes = sequencer.getNotes();
    for( int i = 0; i < notes.length(); i++ ) {
        notes.at( i )->setBeat( i * 2 );
    }

    controller.setSequencer( &sequencer );

    QApplication a(argc, argv);
    MainWindow w( &controller );
    w.show();
    
    return a.exec();
}
