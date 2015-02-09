FLAGS=-std=c++0x -g3 -O0 -Wall -Werror -pedantic
CC=clang++
NAME=agdyne
LINKS=-loleg
INCLUDES=-I./include/

%.o: ./src/%.cpp
	$(CC) $(FLAGS) $(INCLUDES) -c $<

all: graph.o server.o agdyne.o main.o
	$(CC) $(FLAGS) $(INCLUDES) $(LIBS) -pthread -o $(NAME) $^ $(LINKS)

clean:
	rm *.o
	rm $(NAME)
