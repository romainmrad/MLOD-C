include ../../Makefile/common

PROGRAMS=main tests

all: $(PROGRAMS)

main: main.o echangeContenu.o

run: main
	./main

tests: tests.o echangeContenu.o $(TEST_LIB)

runTests: tests
	./tests

clean:
	@rm -f *.o $(PROGRAMS)

re: clean all

.PHONY: all clean re
