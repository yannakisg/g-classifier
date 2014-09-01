CC=cc
CFLAGS=-c
LDFLAGS= -lm
SOURCES=src/main.c src/io.c src/decisionTree.c src/linkedlist.c src/mempool.c src/classifier.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=pgclassifier

all: $(SOURCES) $(EXECUTABLE)

clean: 
	rm $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	rm src/*.o
.c.o:
	$(CC) $(CFLAGS) $< -o $@

