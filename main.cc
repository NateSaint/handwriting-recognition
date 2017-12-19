#include "readMNIST.h"

using namespace std;

int main ()
{
	vector<int> trainingLabels;
	vector<vector<int> > trainingImages;

	// Populate vector with training labels
	trainingLabels = readLabelFile("train-labels-idx1-ubyte");

	// Populate vector of vectors with training images information
	trainingImages = readImageFile("train-images-idx3-ubyte");

	return 0;
}