.PHONY: clean

test: main checker
	./checker hw3.c
	./main

main: main.c hw3.c
	gcc -o main main.c hw3.c

clean:
	-@rm -f main
