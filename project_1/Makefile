project: user_interface.o database.o
	gcc -o project user_interface.o database.o

database.o: database.c record.h database.h
	gcc -ansi -pedantic-errors -Wall -c database.c

user_interface.o: user_interface.c record.h database.h
	gcc -ansi -pedantic-errors -Wall -c user_interface.c
