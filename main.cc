#include "readMNIST.h"
#include "helperFunctions.h"

using namespace std;

int main ()
{
	vector<int> targetResults;
	vector<vector<int> > trainingImages;

	// Populate vector with the target/correct results corresponding to the training images
	targetResults = readLabelFile("train-labels-idx1-ubyte");

	// Populate vector of vectors with training images information
	trainingImages = readImageFile("train-images-idx3-ubyte");

	return 0;
}