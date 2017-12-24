all: run

run: main.cc readMNIST.cc readMNIST.h helperFunctions.cc helperFunctions.h
	g++ -o run main.cc readMNIST.cc helperFunctions.cc
