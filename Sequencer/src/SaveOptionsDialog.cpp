#include "include/SaveOptionsDialog.h"

SaveOptionsDialog::SaveOptionsDialog( QWidget *parent )
    : QDialog::QDialog( parent ) {
    m_cancelButton = new QPushButton( QString( "Cancel" ), this );
    m_saveButton = new QPushButton( QString( "Save" ), this );
    m_repeatBox = new QSpinBox( this );
    m_numberOfRepeatsLabel = new QLabel( QString( "number of repeats:" ), this );

    m_mainLayout = new QVBoxLayout( this );
    m_cancelSave = new QHBoxLayout( this );
    m_labelSpinner = new QHBoxLayout( this );

    m_cancelSave->addWidget( m_cancelButton );
    m_cancelSave->addWidget( m_saveButton );

    m_labelSpinner->addWidget( m_numberOfRepeatsLabel );
    m_labelSpinner->addWidget( m_repeatBox );

    m_mainLayout->addItem( m_labelSpinner );
    m_mainLayout->addItem( m_cancelSave );

    setWindowModality( Qt::WindowModal );
    setWindowTitle( tr( "Save WAV" ) );
}
