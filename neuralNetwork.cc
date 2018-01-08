/**
 * Functions for training and testing the neural network.
 *
 * AUTHOR: Nathen St. Germain
 * DATE: January 2, 2017
 */

#include "neuralNetwork.h"

using namespace std;

vector<vector<float> > trainNetwork (vector<vector<int> > images, vector<int> labels) {
	int numCorrect = 0;
	vector<vector<float> > weights;

	// Set initial weights for neural network
	weights = genWeights();

	// Loop through all training images
	for (int i = 0; i < images.size(); i++)
	{
		float inputLayer[784];
		float outputLayer[10];
		float correctOutput[10];

		setInputLayer(inputLayer, images[i]);
		setCorrectOutput(correctOutput, labels[i]);

		// Determine the output layer for the ith training image
		computeOutputLayer(outputLayer, inputLayer, weights);

		// If classification is correct, increment counter
		if (checkOutput(correctOutput) == checkOutput(outputLayer))
		{
			numCorrect++;
		}

		// Adjust weights (delta rule (gradient descent))
		weights = adjustWeights(weights, inputLayer, outputLayer, correctOutput, 0.3);
	}

	// Print the classification results from training
	cout << "Number of images correctly classified in training:\n" << numCorrect << 
		" / " << images.size() << " = " << ((float)numCorrect/images.size())*100.0 << "% classification" << endl;

	return weights;
}

void testNetwork (vector<vector<float> > weights, vector<vector<int> > images, vector<int> labels)
{
	int numCorrect = 0;

	for (int i = 0; i < images.size(); i++)
	{
		float inputLayer[784];
		float outputLayer[10];

		setInputLayer(inputLayer, images[i]);
		computeOutputLayer(outputLayer, inputLayer, weights);

		// If classification is correct, increment counter
		if (labels[i] == checkOutput(outputLayer))
		{
			numCorrect++;
		}
	}

	// Print the classification results from testing
	cout << "Number of images correctly classified:\n" << numCorrect << 
		" / " << images.size() << " = " << ((float)numCorrect/images.size())*100.0 << "% classification" << endl;
}

int checkOutput (float outputLayer[10])
{
	int greatestPos = 0;
	for (int i = 0; i < 10; i++)
	{
		if (outputLayer[i] > outputLayer[greatestPos])
		{
			greatestPos = i;
		}
	}
	return greatestPos;
}

vector<vector<float> > adjustWeights (vector<vector<float> > weights, float inputLayer[784], float outputLayer[10], float correctOutput[10], float learningRate)
{
	vector<vector<float> > updatedWeights;

	for (int i = 0; i < 10; i++)
	{
		vector<float> temp;
		
		for (int j = 0; j < 784; j++)
		{
			// Using the Delta rule (Gradient descent learning rule), to update the weights
			temp.push_back(weights[i][j] + (learningRate*inputLayer[j]/255*(correctOutput[i] - outputLayer[i])));
		}

		updatedWeights.push_back(temp);
	}

	return updatedWeights;
}

void computeOutputLayer (float outputLayer[10], float inputLayer[784], vector<vector<float> > weights)
{
	for (int i = 0; i < 10; i++)
	{
		outputLayer[i] = weightedSumInput(inputLayer, weights[i]) / 784;
	}
}

float weightedSumInput (float inputLayer[784], vector<float> weights)
{
	float sum = 0;

	for (int i = 0; i < 784; i++)
	{
		//cout << inputLayer[i] << " " << weights[i] << endl;
		sum += (inputLayer[i]/255) * weights[i];
	}

	return sum;
}

vector<vector<float> > genWeights ()
{
	vector<vector<float> > weights;

	// Generate 10 sets of 784 weights
	for (int i = 0; i < 10; i++)
	{
		vector<float> temp;
		for (int j = 0; j < 784; j++)
		{
			temp.push_back(0);
		}
		weights.push_back(temp);
	}

	return weights;
}

void setInputLayer (float inputLayer[784], vector<int> pixels)
{
	for (int i = 0; i < 784; i++)
	{
		// change [0,255] range to [0,1]
		inputLayer[i] = (float)pixels[i];
	}
}

void setCorrectOutput (float correctOutput[10], int label)
{
	for (int i = 0; i < 10; i++)
	{
		if (label == i)
			correctOutput[i] = 1;
		else
			correctOutput[i] = 0;
	}
}