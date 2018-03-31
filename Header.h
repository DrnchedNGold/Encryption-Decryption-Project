#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <string>
#include <windows.h>

using namespace std;

void charconverter(int i, char storage[], int part2[], int y) {
	//The element from the character array is stored into an integer array

	for (int O = 1; O <= i; O++) {

		if (O > (i - y)) {
			for (int c = 1; c <= y; c++)
			{
				part2[O] = 0;
				O++;

				//The Fillers are going to be 0
			}
			break;
		}

		if (storage[O] == '.')
			part2[O] = 117;

		else if (storage[O] == ' ')
			part2[O] = 1;

		else {
			int a = part2[O];
			int b = (part2[O]) - 64;

			a = 64 + (2 * b);

			part2[O] = a;
		}
		// The formula is 64 + 2((part 2 value) - 64)
		// For example, a = 65 in ASCII. A becomes 64 + 2(65-64) or 66
	}
}





void arrangement1x3(int i, int part2[], int ptm[7][300]) 
{
	//For loop which stores each 3 terms down by rows in a separate column of one matrix

	cout << endl;
	

	// "ptm" = Plain Text Matrix (1x3 matrices)

	int h = 1;

	for (int c = 1; c <= (i / 3); c++) {

		for (int r = 1; r <= 3; r++) {
			int a = part2[h];
			ptm[r][c] = a;
			h++;
			cout << ptm[r][c] << "  ";
		}
		cout << endl;
	}
}





void matrixmult (int i, int random[3][3], int ptm[7][300]) 
{

	//Cipher Text Matrix = "ctm"
	int ctm[7][300];


	for (int c = 1; c <= (i / 3); c++) {

		for (int w = 0; w < 3; w++) {
			int a = 0;
			int r = 1;
			for (int q = 0; q < 3; q++) {

				a = a + (random[w][q] * ptm[r][c]);
				r++;
			}

			ctm[w][c] = a;

		}
	}

	for (int c = 1; c <= (i / 3); c++) {
		for (int w = 0; w < 3; w++)
			cout << ctm[w][c] << "     ";

		cout << endl;
	}
	
}