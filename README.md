# handwriting-recognition-neural-network
***** Neural network to recognize handwritten digits *****

First time implementing a neural network. Trained and tested using the MNIST dataset for handwritten digits.

-- Programming done using C++, no machine learning libraries were used--

Libraries used:
  -<iostream>
  -<fstream>
  -<vector>
  -<cstdlib>
  -<ctime>

Compilation:
  -"g++ -o run main.cc readMNIST.cc helperFunctions.cc neuralNetwork.cc"
  -I have included a makefile to see an example of my compilation.
  -(All .cc files are compiled with g++ in my testing)
      -.h files are named the same as their respective .cc file

Running:
  -Ensure the provided training and testing files are unzipped and the file names are unchanged
      -The names expected are:
          -"train-labels-idx1-ubyte"
          -"train-images-idx3-ubyte"
          -"t10k-labels-idx1-ubyte"
          -"t10k-images-idx3-ubyte"
  -Run the executable generated after compiling.
      -"./run"
