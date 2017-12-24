/**
 * Functions to parse image and label files for handwritten digits 
 * from the MNIST dataset.  Where the files can be found and what 
 * the parsing is based off is found at:
 * http://yann.lecun.com/exdb/mnist/
 *
 * AUTHOR: Nathen St. Germain
 * DATE: December 19, 2017
 */
#include "readMNIST.h"

using namespace std;

vector<int> readLabelFile (string fileName)
{
	vector<int> labels;
	uint32_t magicNumber;
	uint32_t numItems;

	magicNumber = 0;
	numItems = 0;

	ifstream f (fileName, ios::binary);

	if (f.is_open())
	{
		// Read the magic number and number of items
		f.read((char*)&magicNumber, sizeof(uint32_t));
		f.read((char*)&numItems, sizeof(uint32_t));

		// Change format of values for low-endian machines
		magicNumber = reverse(magicNumber);
		numItems = reverse(numItems);

		// Read the label values
		for (int i = 0; i < numItems; i++)
		{
			unsigned char labelValue;
			labelValue = 0;
			f.read((char*)&labelValue, sizeof(unsigned char));

			labels.push_back((int)labelValue);
		}
	}
	f.close();
	
	return labels;
}

vector<vector<int> > readImageFile (string fileName)
{
	vector<vector<int> > images;
	uint32_t magicNumber;
	uint32_t numImages;
	uint32_t numRows;
	uint32_t numCols;

	magicNumber = 0;
	numImages = 0;
	numRows = 0;
	numCols = 0;

	ifstream f (fileName, ios::binary);

	if (f.is_open())
	{
		// Read the magic number and number of items
		f.read((char*)&magicNumber, sizeof(uint32_t));
		f.read((char*)&numImages, sizeof(uint32_t));
		f.read((char*)&numRows, sizeof(uint32_t));
		f.read((char*)&numCols, sizeof(uint32_t));

		// Change format of the 32-bit values for low-endian machines
		magicNumber = reverse(magicNumber);
		numImages = reverse(numImages);
		numRows = reverse(numRows);
		numCols = reverse(numCols);

		// Read the image information
		for (int i = 0; i < numImages; i++)
		{
			vector<int> temp;
			for (int j = 0; j < numRows; j++)
			{
				for (int k = 0; k < numCols; k++)
				{
					unsigned char val;
					val = 0;
					f.read((char*)&val, sizeof(unsigned char));
					temp.push_back((int)val);
				}
			}
			images.push_back(temp);
		}
	}
	f.close();

	return images;
}

int32_t reverse (int32_t toReverse)
{
	uint32_t reversed;

	reversed = (toReverse & 0x000000FF) << 24 | (toReverse & 0x0000FF00) << 8 |
	(toReverse & 0x00FF0000) >> 8 | (toReverse & 0xFF000000) >> 24;

	return reversed;
}