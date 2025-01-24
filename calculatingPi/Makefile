
EXE=piReduction
CC=gcc 
CFLAGS= -pg -std=c99 -Wall -Ofast
LIBS = -fopenmp


all: $(EXE)

$(EXE): $(EXE).c
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

.PHONY: all clean

clean:
	rm -f $(EXE)
