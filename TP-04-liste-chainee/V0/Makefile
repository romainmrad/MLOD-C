include ../../Makefile/common

PROGRAMS=liste-chainee-main

all: $(PROGRAMS)

liste-chainee-main: liste-chainee-main.c liste-chainee.c
	gcc -W -Wall -o liste-chainee-main liste-chainee-main.c liste-chainee.c

run: liste-chainee-main
	./liste-chainee-main

clean:
	@rm -f *.o $(PROGRAMS)

re: clean all

.PHONY: all clean re
