CC=gcc
AR=ar
FLAGS=-Wall -g
LIBS=-lm
OBJECTS_MAIN=main.o
OBJECTS_GRAPH=graph.o

all: libgraph.a graph

graph:	$(OBJECTS_MAIN) libgraph.a 
	$(CC) $(FLAGS) -o graph $(OBJECTS_MAIN) libgraph.a $(LIBS)


libgraph.a:	$(OBJECTS_GRAPH)
	$(AR) -rcs libgraph.a $(OBJECTS_GRAPH)
	
main.o:	main.c graph.h
	$(CC) $(FLAGS) -c main.c
graph.o: graph.c graph.h
	$(CC) $(FLAGS) -c graph.c $(LIBS)

.PHONY: clean all

clean:
	rm -f *.o *.a graph