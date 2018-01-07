# handwriting-recognition-neural-network
## ***** Neural network to recognize handwritten digits *****

### First time implementing a neural network. Trained and tested using the MNIST dataset for handwritten digits.

### -- Programming done using C++, no machine learning libraries were used--

  This is a single-layer neural network trained using the Delta rule which is a gradient descent learning rule for 
updating weights.  The input neurons are the brightness levels for each pixel of each image provided in the MNIST dataset.
The weights are initially randomly (pseudo) assigned a value in the range 0 to 1, inclusive, and the brightness level of
each pixel is adjusted to be in the range 0 to 1 instead of 0 to 255, both inclusive, (where 255 is black and 0 is white).
The output layer is 10 output neurons, each having a value between 0 and 1, inclusive.  The greatest value is the digit that 
the neural network will classify the image as.
  
  The weighted sum of the input neurons (transformed to the scale 0 to 1, inclusive) is how the values in the output layer 
are determined.  Everytime an output layer is computed, the error is calculated and the weights are adjusted using the Delta 
rule, which makes use of gradient descent.  I used a learning rate of 0.5 in my testing.

#### Links to the resources I used:
  * Where I learned about the Delta rule: <https://en.wikipedia.org/wiki/Delta_rule>
  * MNIST Dataset: <http://yann.lecun.com/exdb/mnist/>
  
#### Libraries used:
  * iostream
  * fstream
  * vector
  * cstdlib
  * ctime

#### Compilation:
  * g++ -o run main.cc readMNIST.cc helperFunctions.cc neuralNetwork.cc
  * I have included a makefile to see an example of my compilation.
  * (All .cc files are compiled with g++ in my testing)
      * .h files are named the same as their respective .cc file

#### Running:
  * Ensure the provided training and testing files are uncompressed and the file names are unchanged
      * The names expected are:
          * train-labels-idx1-ubyte
          * train-images-idx3-ubyte
          * t10k-labels-idx1-ubyte
          * t10k-images-idx3-ubyte
  * Run the executable generated after compiling.
      * ./run
