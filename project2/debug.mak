project_debug: llist.o user_interface.o
	g++ -o project_debug llist.o user_interface.o

llist.o: llist.cpp llist.h
	g++ -ansi -pedantic-errors -Wall -c -D DEBUG llist.cpp

user_interface.o: user_interface.cpp llist.h
	g++ -ansi -pedantic-errors -Wall -c -D DEBUG user_interface.cpp
