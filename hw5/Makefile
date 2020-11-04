.PHONY: clean test

test: main
	./checker address.c
	./main

main: main.o address.o
	gcc -o main main.o address.o

address.o: address.c
	gcc -c address.c

main.o: main.c
	gcc -c main.c

clean:
	-@rm -f main *.o *.bin
