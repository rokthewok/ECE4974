# This will be my makefile!

inc = include
src = src
bin = bin

obj = $(bin)/main.o $(bin)/WavWriter.o $(bin)/ByteConverter.o

wav_writer: $(obj)
	g++ -o wav_writer $(obj)

main.o: $(src)/main.cpp $(inc)/WavWriter.h
	g++ -c $(src)/main.cpp -o $(bin)/main.o

WavWriter.o: $(src)/WavWriter.cpp $(inc)/WavWriter.h
	g++ -c $(src)/WavWriter/cpp $(bin)/WavWriter.o

ByteConverter.o: $(src)/ByteConverter.cpp $(inc)/ByteConverter.h
	g++ -c $(src)/ByteConverter.cpp $(bin)/ByteConverter.o

clean:
	rm $(bin)/*.o
