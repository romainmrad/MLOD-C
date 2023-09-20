include ../../Makefile/common

PROGRAMS=main

all: $(PROGRAMS)

main: main.o date.o

run: main
	./main

clean:
	@rm -f *.o $(PROGRAMS)

re: clean all

.PHONY: all clean re
