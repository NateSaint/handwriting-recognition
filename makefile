all: run

run: main.cc readMNIST.cc readMNIST.h helperFunctions.cc helperFunctions.h neuralNetwork.cc neuralNetwork.h
	g++ -o run main.cc readMNIST.cc helperFunctions.cc neuralNetwork.cc
