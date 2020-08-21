.PHONY: clean

test: main checker
	./checker hw1.c
	./main

main: main.c hw1.c
	gcc -o main main.c hw1.c

clean:
	-@rm -f main
