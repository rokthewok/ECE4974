# This will be my makefile!

VPATH = src::bin:include

CFLAGS = -g -Iinclude -lm
bin = bin
obj = osc_test.o Oscillator.o FmOscillator.o SineOscillator.o
binobj = $(bin)/osc_test.o $(bin)/Oscillator.o $(bin)/FmOscillator.o $(bin)/SineOscillator.o

osc_test : $(obj)
	g++ -ljack -o osc_test $(binobj)

osc_test.o : osc_test.cpp
	g++ $(CFLAGS) -c src/osc_test.cpp -o $(bin)/osc_test.o

Oscillator.o : Oscillator.cpp Oscillator.h
	g++ $(CFLAGS) -c src/Oscillator.cpp -o $(bin)/Oscillator.o

FmOscillator.o : FmOscillator.cpp FmOscillator.h
	g++ $(CFLAGS) -c src/FmOscillator.cpp -o $(bin)/FmOscillator.o

SineOscillator.o : SineOscillator.cpp SineOscillator.h
	g++ $(CFLAGS) -c src/SineOscillator.cpp -o $(bin)/SineOscillator.o

clean :
	rm -f $(bin)/*.o osc_test
