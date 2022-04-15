all: main  Server

main: user_interface.o main.c
	gcc main.c user_interface.c -o main

user_interface.o: user_interface.c user_interface.h
	gcc -c user_interface.c -o user_interface.o

Server: Server.c
	gcc Server.c -o Server

clean:
	rm -rf main *.o Server
