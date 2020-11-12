.PHONY: clean test

test: main
	./checker linked.c
	./main

main: main.o linked.o utils.o
	gcc -o main main.o utils.o linked.o

linked.o: linked.c
	gcc -c linked.c

utils.o: utils.c
	gcc -c utils.c

main.o: main.c
	gcc -c main.c

clean:
	-@rm -f main *.o *.bin
