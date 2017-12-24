/**
 * Helper functions for miscellaneous tasks.
 *
 * AUTHOR: Nathen St. Germain
 * DATE: December 24, 2017
 */
#include "helperFunctions.h"

using namespace std;

void displayImageAsText (int index, int height, int width, vector<vector<int> > images, vector<int> labels)
{
	cout << "Image #: " << index + 1 << endl;
	cout << "Label: " << labels[index];
	for (int i = 0; i < (height * width); i++)
	{
		if (images[index][i] == 0)
			cout << ' ';
		else
			cout << 0;

		if ((i + 1) % width == 0)
			cout << endl;
	}
}