# -*- Makefile -*-

all: TestStaticArray

TestStaticArray: TestStaticArray.o StaticArray.o ../../misc/DisplayMenu.o
	g++ TestStaticArray.o StaticArray.o ../../misc/DisplayMenu.o -o TestStaticArray

TestStaticArray.o: TestStaticArray.cpp
	g++ TestStaticArray.cpp -c

StaticArray.o: StaticArray.cpp
	g++ StaticArray.cpp -c

DisplayMenu.o: ../../misc/DisplayMenu.cpp
	g++ ../../misc/DisplayMenu.cpp -c
