ATM.out : main.o server.o database.o
	g++ -o ATM.out main.o server.o database.o

main.o :
	g++ -c main.cpp

server.o :
	g++ -c server.cpp

database.o :
	g++ -c database.cpp
