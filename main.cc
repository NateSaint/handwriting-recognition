#include "readMNIST.h"
#include "helperFunctions.h"
#include "neuralNetwork.h"

using namespace std;

int main ()
{
	vector<int> trainingLabels;
	vector<int> testingLabels;
	vector<vector<int> > trainingImages;
	vector<vector<int> > testingImages;
	vector<vector<float> > trainedWeights;

	/**
	 * Parsing label and image files
	 */

	// Populate vector with the target/correct results corresponding to the training images
	cout << "Reading training labels..." << endl;
	trainingLabels = readLabelFile("train-labels-idx1-ubyte");
	cout << "Successfully read training labels" << endl;

	// Populate vector of vectors with training images information
	cout << "Reading training images..." << endl;
	trainingImages = readImageFile("train-images-idx3-ubyte");
	cout << "Successfully read training images" << endl;

	// Populate vector with the target/correct results corresponding to the testing images
	cout << "Reading testing labels..." << endl;
	testingLabels = readLabelFile("t10k-labels-idx1-ubyte");
	cout << "Successfully read testing labels" << endl;

	// Populate vector of vectors with testing images information
	cout << "Reading testing images..." << endl;
	testingImages = readImageFile("t10k-images-idx3-ubyte");
	cout << "Successfully read testing images\n" << endl;


	/**
	 * Training and testing neural network using label and image files
	 */
	cout << "Training neural network..." << endl;
	trainedWeights = trainNetwork(trainingImages, trainingLabels);
	cout << "Done training neural network\n\n" << endl;

	cout << "Testing neural network..." << endl;
	testNetwork(trainedWeights, testingImages, testingLabels);
	cout << "Done testing neural network\n\n" << endl;

	return 0;
}