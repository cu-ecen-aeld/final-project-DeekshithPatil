all: main user_interface.o Server

main: user_interface.o main.c
	gcc `pkg-config --cflags gtk+-3.0` -o main user_interface.o main.c `pkg-config --libs gtk+-3.0`

user_interface.o: user_interface.c user_interface.h
	gcc `pkg-config --cflags gtk+-3.0` -o user_interface.o -c user_interface.c `pkg-config --libs gtk+-3.0`

Server: Server.c
	gcc Server.c -o Server


clean:
	rm -rf main
	rm -rf main.o
	rm -rf user_interface.o
	rm -rf Server
