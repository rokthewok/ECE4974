# This will be my makefile!

VPATH = src:bin:include

CFLAGS = -Iinclude -lm
bin = bin
obj = main.o WavWriter.o ByteConverter.o Oscillator.o SineOscillator.o TriangleOscillator.o RisingSawtoothOscillator.o
binobj = $(bin)/main.o $(bin)/WavWriter.o $(bin)/ByteConverter.o $(bin)/Oscillator.o $(bin)/SineOscillator.o \
$(bin)/TriangleOscillator.o $(bin)/RisingSawtoothOscillator.o

wav_writer : $(obj)
	g++ -o wav_writer $(binobj)

main.o : main.cpp WavWriter.h
	g++ $(CFLAGS) -c src/main.cpp -o $(bin)/main.o

WavWriter.o : WavWriter.cpp WavWriter.h
	g++ $(CFLAGS) -c src/WavWriter.cpp -o $(bin)/WavWriter.o

ByteConverter.o : ByteConverter.cpp ByteConverter.h
	g++ $(CFLAGS) -c src/ByteConverter.cpp -o $(bin)/ByteConverter.o

Oscillator.o : Oscillator.cpp Oscillator.h
	g++ $(CFLAGS) -c src/Oscillator.cpp -o $(bin)/Oscillator.o

SineOscillator.o : SineOscillator.cpp SineOscillator.h
	g++ $(CFLAGS) -c src/SineOscillator.cpp -o $(bin)/SineOscillator.o

TriangleOscillator.o : TriangleOscillator.cpp TriangleOscillator.h
	g++ $(CFLAGS) -c src/TriangleOscillator.cpp -o $(bin)/TriangleOscillator.o

RisingSawtoothOscillator.o : RisingSawtoothOscillator.cpp RisingSawtoothOscillator.h
	g++ $(CFLAGS) -c src/RisingSawtoothOscillator.cpp -o $(bin)/RisingSawtoothOscillator.o

clean :
	rm -f $(bin)/*.o wav_writer
