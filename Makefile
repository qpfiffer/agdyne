FLAGS=-std=c++0x -g3 -O0 -Wall
CC=clang++
NAME=agdyne
SOPHIA_DIR=./deps/sophia/sophia/
INCLUDES=-I$(SOPHIA_DIR) -I./include/
LIBS=-L$(SOPHIA_DIR)
LINKS=-lsophia

%.o: ./src/%.cpp
	$(CC) $(FLAGS) $(INCLUDES) -c $<

all: graph.o main.o
	$(CC) $(FLAGS) $(INCLUDES) $(LIBS) -pthread -o $(NAME) $^ $(SOPHIA_DIR)libsophia.a $(LINKS)

clean:
	rm *.o
	rm $(NAME)
