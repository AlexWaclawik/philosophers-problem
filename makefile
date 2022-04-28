#makeFile for Program

CFLAGS = -g -Wall

#copied from last program not updated yet
main.o: main.cpp Runner.h Mailbox.h Changer.h Philosopher.h
	g++ $(CFLAGS) -c main.cpp

Philosopher.o: Philosopher.cpp Philosopher.h Runner.h Changer.h
	g++ $(CFLAGS) -c Philosopher.cpp

Runner.o: Runner.cpp Runner.h Changer.h Mailbox.h
	g++ $(CFLAGS) -c Runner.cpp

Changer.o: Changer.cpp Changer.h Runner.h Mailbox.h
	g++ $(CFLAGS) -c Changer.cpp

Mailbox.o: Mailbox.cpp Mailbox.h
	g++ $(CFLAGS) -c Mailbox.cpp

program: main.o Philosopher.o Runner.o Changer.o Mailbox.o
	g++ $(CFLAGS) main.o Mailbox.o Philosopher.o Runner.o Changer.o -o program

clean:
	rm *.o
	rm program

debug:
	gdb ./program

run: program
	./program