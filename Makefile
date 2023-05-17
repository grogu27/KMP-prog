KMP : main.o funk.o
	gcc main.o funk.o -o KMP

main.o : main.c
	gcc -c main.c -o main.o

funk.o : funk.c
	gcc -c funk.c -o funk.o


run:
	./KMP

clean:
	rm *.o

