CC = g++
CPPFLAGS = -std=c++11 -Wall -g

process: datalogger.o linkedlist.o sensordata.o process.o

datalogger.o: datalogger.h linkedlist.h

linkedlist.o: linkedlist.h sensordata.h

sensordata.o: sensordata.h

process.o: datalogger.h

clean:
	rm main *.o