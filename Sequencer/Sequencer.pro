#-------------------------------------------------
#
# Project created by QtCreator 2012-11-28T17:01:44
#
#-------------------------------------------------

QT       += core gui

LIBS += -ljack
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
    src/JackSequencerController.cpp \
    src/OscillatorFactory.cpp \
    src/SineBuilder.cpp \
    src/FmBuilder.cpp \
    src/RisingSawtoothBuilder.cpp \
    src/TriangleBuilder.cpp \
    src/OscilatorBuilder.cpp \
    src/WavDataBuilder.cpp

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
    include/JackSequencerController.h \
    include/Pitch.h \
    include/Wavetype.h \
    include/OscillatorFactory.h \
    include/OscillatorBuilder.h \
    include/SineBuilder.h \
    include/FmBuilder.h \
    include/RisingSawtoothBuilder.h \
    include/TriangleBuilder.h \
    include/WavDataBuilder.h

FORMS    += mainwindow.ui
