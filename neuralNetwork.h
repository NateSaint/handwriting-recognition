/**
 * Functions for training and testing the neural network.
 *
 * AUTHOR: Nathen St. Germain
 * DATE: January 2, 2017
 */
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

/**
 * Train the neural network, in other words, determine what the weights of 
 * each input neuron in the input layer should be.
 *
 * Params: vector<vector<int>>: vector describing pixel information of images,
 *         vector<int>: vector containing the labels of the images
 * Return: vector<vector<float>>: vector describing weights after training
 */
std::vector<std::vector<float> > trainNetwork (std::vector<std::vector<int> > images, 
	std::vector<int> labels);

/**
 * Test the neural network based on the input neuron weights found previously 
 * when training the neural network.
 *
 * Params: vector<vector<float>>: vector describing weights of the input neurons,
 *         vector<vector<int>>: vector describing pixel information of images,
 *         vector<int>: vector containing the labels of the images
 */
void testNetwork (std::vector<std::vector<float> > weights, 
	std::vector<std::vector<int> > images, std::vector<int> labels);

/**
 * Determine what the output layer classified as an int.
 *
 * Params: float: array representing the output layer
 * Return: int: classification from the network
 */
int checkOutput (float outputLayer[10]);

/**
 * Adjust the weights for the neural network.  Uses the Delta rule.
 *
 * Params: vector<vector<float>>: weights for the network, float: array of pixel brightness in input layer, 
 *        float: array representing the output layer, float: array representing the desired/correct output, 
 *        float: the learning rate of the network
 * Return: vector<vector<float>>: vector storing the adjusted weights
 */
std::vector<std::vector<float> > adjustWeights (std::vector<std::vector<float> > weights, float inputLayer[784], 
	float outputLayer[10], float correctOutput[10], float learningRate);

/**
 * Compute the output layer for the neural network.  The output layer consists of 
 * 10 values each representing the networks choice as to what the image is.
 *
 * Params: float: array representing the output layer, float: array representing the input layer, 
 *.        vector<vector<float>>: vector representing the weights
 */
void computeOutputLayer (float outputLayer[10], float inputLayer[784], std::vector<std::vector<float> > weights);

/**
 * Take the weighted sum of the input layer and it's respective weights.
 *
 * Params: float: array representing the input layer, vector<float>: vector representing weights
 */
float weightedSumInput (float inputLayer[784], std::vector<float> weights);

/**
 * Generate weights to be 0.5 to start.
 *
 * Return: vector<vector<float>>: vector storing the weights
 */
std::vector<std::vector<float> > genWeights ();

/**
 * Set the array representing the input layer of the neural network with the pixel 
 * brightness from [0,1].  Pixel brightness is defined from [0,255] in the vector.
 *
 * Params: array of floats representing the input layer, vector<int> pixel values of image
 */
void setInputLayer (float inputLayer[784], std::vector<int> pixels);

/**
 * Set the array representing the correct output to represent a given label.  The position 
 * of the 1 in the array will represent which label the array represents.
 *
 * Params: float array representing a digit, int: label the array should represent
 */
void setCorrectOutput (float correctOutput[10], int label);