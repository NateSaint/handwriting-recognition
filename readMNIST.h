/**
 * Functions to parse image and label files for handwritten digits 
 * from the MNIST dataset.  Where the files can be found and what 
 * the parsing is based off is found at:
 * http://yann.lecun.com/exdb/mnist/
 *
 * AUTHOR: Nathen St. Germain
 * DATE: December 19, 2017
 */
#include <iostream>
#include <fstream>
#include <vector>

/**
 * Read the "label file" for either the training or dataset.
 *
 * Params: string: name of file
 * Return: vector of integers
 */
std::vector<int> readLabelFile (std::string fileName);

/**
 * Read the "image file" for either the training or dataset.
 *
 * Params: string: name of file
 * Return: vector of integers
 */
std::vector<std::vector<int> > readImageFile (std::string fileName);

/**
 * Convert integers stored in MSB first (high-endian) format
 * to format for low-endian machines (flip bytes of the header).
 *
 * Params: int32_t: integer to convert
 * Return: int32_t: converted integer
 */
int32_t reverse (int32_t toReverse);