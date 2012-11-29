# This will be my makefile!

VPATH = src::bin:include

CFLAGS = -Iinclude -lm
bin = bin
obj = fm_test.o WavWriter.o ByteConverter.o Oscillator.o FmOscillator.o
binobj = $(bin)/fm_test.o $(bin)/WavWriter.o $(bin)/ByteConverter.o $(bin)/Oscillator.o $(bin)/FmOscillator.o

fm_test : $(obj)
	g++ -ljack -o fm_test $(binobj)

fm_test.o : fm_test.cpp WavWriter.h
	g++ $(CFLAGS) -c src/fm_test.cpp -o $(bin)/fm_test.o

WavWriter.o : WavWriter.cpp WavWriter.h
	g++ $(CFLAGS) -c src/WavWriter.cpp -o $(bin)/WavWriter.o

ByteConverter.o : ByteConverter.cpp ByteConverter.h
	g++ $(CFLAGS) -c src/ByteConverter.cpp -o $(bin)/ByteConverter.o

Oscillator.o : Oscillator.cpp Oscillator.h
	g++ $(CFLAGS) -c src/Oscillator.cpp -o $(bin)/Oscillator.o

FmOscillator.o : FmOscillator.cpp FmOscillator.h
	g++ $(CFLAGS) -c src/FmOscillator.cpp -o $(bin)/FmOscillator.o

clean :
	rm -f $(bin)/*.o fm_test
