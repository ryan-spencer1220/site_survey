CC=g++
CPPFLAGS = -std=c++11 -I. -g
DEPS = dlist.h
OBJ = datalogger.o linkedlist.o node.o process.o sensordata.o

%.o: %.cpp $(DEPS)
		$(CC) $(CPPFLAGS) -c -o $@ $<

main: $(OBJ)
		$(CC) $(CPPFLAGS) -o $@ $^

clean:
		rm	-f *.o main
