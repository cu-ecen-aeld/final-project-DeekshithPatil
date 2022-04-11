all: main

main: main.c user_interface.o
	gcc -Wall -Werror -g main.c user_interface.o -o main

user_interface: user_interface.c user_interface.h
	gcc -Wall -Werror -g user_interface.c -o user_interface.o

clean:
	rm -rf main

