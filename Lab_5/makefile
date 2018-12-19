.PHONY: all clean

all: task

clean: 
	rm *.o
	rm task

task: main.o libList.so
	gcc -L . -lList -o task  main.o

main.o: main.c list.h
	gcc -c main.c

libList.so: list.o
	gcc -shared -o libList.so list.o

list.o: list.c list.h
	gcc -c -fPIC list.c
