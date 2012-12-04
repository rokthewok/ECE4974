#-------------------------------------------------
#
# Project created by QtCreator 2012-11-28T17:01:44
#
#-------------------------------------------------

QT       += core gui

TARGET = Sequencer
TEMPLATE = app


SOURCES += src/main.cpp\
        src/MainWindow.cpp \
    src/WavWriter.cpp \
    src/TriangleOscillator.cpp \
    src/SineOscillator.cpp \
    src/RisingSawtoothOscillator.cpp \
    src/Oscillator.cpp \
    src/FmOscillator.cpp \
    src/ByteConverter.cpp \
    src/Note.cpp \
    src/Sequencer.cpp \
    src/JackSequencerController.cpp

HEADERS  += include/MainWindow.h \
    include/WavWriter.h \
    include/TriangleOscillator.h \
    include/SineOscillator.h \
    include/RisingSawtoothOscillator.h \
    include/Oscillator.h \
    include/FmOscillator.h \
    include/ByteConverter.h \
    include/Note.h \
    include/Sequencer.h \
    include/AbstractSequencerController.h \
    include/JackSequencerController.h

FORMS    += mainwindow.ui
