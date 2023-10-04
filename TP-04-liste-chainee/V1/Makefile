include ../../Makefile/common

PROGRAMS=linkedListOfString

all: $(PROGRAMS)

linkedListOfString: linkedListOfString.c linkedList.c
	gcc -W -Wall -std=c99 linkedList.c linkedListOfString.c -o linkedListOfString

run: linkedListOfString
	./linkedListOfString

clean:
	@rm -f *.o $(PROGRAMS)

re: clean all

.PHONY: all clean re
