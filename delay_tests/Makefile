# This will be my makefile!

CFLAGS = -g -lm -ljack
obj = seq_test.o JackSequencerController.o Sequencer.o Note.o Oscillator.o SineOscillator.o

seq_test : $(obj)
	g++ $(CFLAGS) -o seq_test $(obj)

seq_test.o : seq_test.cpp
	g++ $(CFLAGS) -c seq_test.cpp -o seq_test.o

JackSequencerController.o : JackSequencerController.cpp JackSequencerController.h
	g++ $(CFLAGS) -c JackSequencerController.cpp

Sequencer.o : Sequencer.cpp Sequencer.h
	g++ $(CFLAGS) -c Sequencer.cpp

Note.o : Note.cpp Note.h
	g++ $(CFLAGS) -c Note.cpp -o Note.o

Oscillator.o : Oscillator.cpp Oscillator.h
	g++ $(CFLAGS) -c Oscillator.cpp -o Oscillator.o

SineOscillator.o : SineOscillator.cpp SineOscillator.h
	g++ $(CFLAGS) -c SineOscillator.cpp -o SineOscillator.o

clean :
	rm -f *.o seq_test
