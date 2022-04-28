#makeFile for Program

CFLAGS = -g -Wall


main.o: main.cpp Runner.h Mailbox.h Changer.h Philosopher.h FileIO.h
	g++ $(CFLAGS) -c main.cpp

FileIO.o: FileIO.cpp Fileio.h input.txt
	g++ $(CFLAGS) -c FileIO.cpp

Philosopher.o: Philosopher.cpp Philosopher.h Runner.h Changer.h
	g++ $(CFLAGS) -c Philosopher.cpp

Runner.o: Runner.cpp Runner.h Changer.h Mailbox.h Philosopher.h
	g++ $(CFLAGS) -c Runner.cpp

Changer.o: Changer.cpp Changer.h Runner.h Mailbox.h
	g++ $(CFLAGS) -c Changer.cpp

Mailbox.o: Mailbox.cpp Mailbox.h
	g++ $(CFLAGS) -c Mailbox.cpp

program: main.o Philosopher.o Runner.o Changer.o Mailbox.o FileIO.o
	g++ $(CFLAGS) main.o Mailbox.o Philosopher.o Runner.o Changer.o FileIO.o -o program

clean:
	rm *.o
	rm program

debug:
	gdb ./program

run: program
	./program
