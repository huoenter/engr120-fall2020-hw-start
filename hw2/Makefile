.PHONY: clean

test: main checker
	./checker hw2.c
	./main

main: main.c hw2.c
	gcc -o main main.c hw2.c

clean:
	-@rm -f main
