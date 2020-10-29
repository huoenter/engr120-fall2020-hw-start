.PHONY: clean test

test: main
	./checker sci_not.c
	./main

main: main.o sci_not.o
	gcc -o main main.o sci_not.o

sci_not.o: sci_not.c
	gcc -c sci_not.c

main.o: main.c
	gcc -c main.c

clean:
	-@rm -f main *.o
