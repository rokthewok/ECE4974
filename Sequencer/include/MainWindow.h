#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    
private:
    Ui::MainWindow *ui;
    JackSequencerController * m_sequencerController;
};

#endif // MAINWINDOW_H
