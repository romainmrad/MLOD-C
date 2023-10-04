include ../Makefile/common

PROGRAMS=prixTuring

all: $(PROGRAMS)

main: prixTuring.o

run: prixTuring
	./prixTuring

test: 
	@diff out.csv turingWinners.csv

clean:
	@rm -f *.o $(PROGRAMS)

re: clean all

.PHONY: all clean re
