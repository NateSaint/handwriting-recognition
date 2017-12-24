/**
 * Helper functions for miscellaneous tasks.
 *
 * AUTHOR: Nathen St. Germain
 * DATE: December 24, 2017
 */
#include <iostream>
#include <vector>

/**
 * Display a text-based visual of the image described in images vector at a given index
 * along with a label of the digit the image is supposed to be. Any pixel with value 0 
 * will be a blank space and any pixel with value > 0 will be represented by a character.
 *
 * Params: int: index of image, int: height in pixels of image, int: width in pixels of image,
 *         vector<vector<int>>: vector describing pixel information of images,
 *         vector<int>: vector containing the labels of the images
 */
void displayImageAsText (int index, int height, int width, 
	std::vector<std::vector<int> > images, std::vector<int> labels);