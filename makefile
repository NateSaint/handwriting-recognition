all: run

run: main.cc readMNIST.cc readMNIST.h
	g++ -o run main.cc readMNIST.cc