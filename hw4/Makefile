.PHONY: clean

sci_not.o: sci_not.c sci_not.h
	gcc -c sci_not.c

main: main.c hw3.c
	gcc -o main main.c hw3.c

clean:
	-@rm -f main
