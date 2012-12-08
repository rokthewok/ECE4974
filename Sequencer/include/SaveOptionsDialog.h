#ifndef SAVEOPTIONSDIALOG_H
#define SAVEOPTIONSDIALOG_H

#include <QDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSpinBox>
#include <QLabel>

class SaveOptionsDialog : public QDialog {
public:
    SaveOptionsDialog( QWidget * parent = 0 );
private:
    QVBoxLayout * m_mainLayout;
    QHBoxLayout * m_cancelSave;
    QHBoxLayout * m_labelSpinner;
    QPushButton * m_cancelButton;
    QPushButton * m_saveButton;
    QSpinBox * m_repeatBox;
    QLabel * m_numberOfRepeatsLabel;
};

#endif // SAVEOPTIONSDIALOG_H
