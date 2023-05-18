kmpmatcher : main.o funk.o
	gcc main.o funk.o -o kmpmatcher

main.o : main.c
	gcc -c main.c -o main.o

funk.o : funk.c
	gcc -c funk.c -o funk.o


run:
	./kmpmatcher

clean:
	rm *.o
	rm kmpmatcher

