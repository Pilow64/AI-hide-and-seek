LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
PROG = main
CC = g++
CPPFLAGS = -Wall -O2
OBJS = main.o Game.o hider.o seeker.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS) $(LIBS)

main.o :
	$(CC) $(CPPFLAGS) -c main.cpp

Game.o :
	$(CC) $(CPPFLAGS) -c Game.cpp

hider.o :
	$(CC) $(CPPFLAGS) -c hider.cpp

seeker.o :
	$(CC) $(CPPFLAGS) -c seeker.cpp

clean :
	rm -f core $(PROG) $(OBJS)
