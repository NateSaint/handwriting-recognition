# handwriting-recognition-neural-network
## ***** Neural network to recognize handwritten digits *****

### First time implementing a neural network. Trained and tested using the MNIST dataset for handwritten digits.

### -- Programming done using C++, no machine learning libraries were used--

  NOTE: This is my first time setting up a neural network, so I decided to avoid the hidden layers... for now.  I 
was told that handwritten digits with the MNIST dataset was a good place to practice.

  This is a single-layer neural network trained using the Delta rule which is a gradient descent learning rule for 
updating weights.  The input neurons are the brightness levels for each pixel of each image provided in the MNIST dataset, 
from 0 to 255, inclusive, where 255 is black and 0 is white. The weights are initially assigned a value of 0, idea being 
that the weights will start having no effect on the output. The output layer is 10 output neurons, each with a value, 
the greatest value corresdonds to the index of the digit that the neural network will classify the image as.

  The weighted sum of the input neurons is how the values in the output layer are determined.  Everytime an output layer 
is computed, the error is calculated and the weights are adjusted using the Delta rule, which makes use of gradient descent.

#### Sample output:
```
Reading training labels...
Successfully read training labels
Reading training images...
Successfully read training images
Reading testing labels...
Successfully read testing labels
Reading testing images...
Successfully read testing images

Training neural network...
Number of images correctly classified in training:
50506 / 60000 = 84.1767% classification
Done training neural network


Testing neural network...
Number of images correctly classified:
8281 / 10000 = 82.81% classification
Done testing neural network
```

#### Links to the resources I used:
  * Where I learned about the Delta rule: <https://en.wikipedia.org/wiki/Delta_rule>
  * Where I learned about the Delta rule and gradient descent: <http://sebastianraschka.com/Articles/2015_singlelayer_neurons.html>
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
