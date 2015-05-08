/*
 * Flood_Fill.cpp
 * Design an algorithm to perform a boundary fill in a 2D array
 *  Created on: May 8, 2015
 *      Author: Athakur
 */

#include <iostream>

using namespace std;

// Dimensions of paint screen
#define M 8
#define N 8

// Recursive fn to replace prev color and all the surrounding pixels with the new color
void flood_fill(int screen[][N], int x, int y, int prevC, int newC)
{
	// Base cases
	if (x < 0 || x >= M || y < 0 || y >= N)
		return;

	// if the color to be replaced is not found, exit
	if (screen[x][y] != prevC)
		return;

	// Replace the color at (x,y)
	screen[x][y] = newC;

	// Recur for north, east, south and west
	flood_fill(screen, x+1, y, prevC, newC);
	flood_fill(screen, x-1, y, prevC, newC);
	flood_fill(screen, x, y+1, prevC, newC);
	flood_fill(screen, x, y-1, prevC, newC);
}

void floodFill(int screen[][N], int x, int y, int newC)
{
	int prevC = screen[x][y];
	cout << "Previous colour was :" << prevC << endl;
	flood_fill(screen, x, y, prevC, newC);
}

int main()
{
	int screen[M][N] = {{1,1,1,1,1,1,1,1},
						{1,1,1,1,1,1,0,0},
						{1,0,0,1,1,0,1,1},
						{1,2,2,2,2,0,1,0},
						{1,1,1,2,2,0,1,0},
						{1,1,1,2,2,2,2,0},
						{1,1,1,1,1,2,1,1},
						{1,1,1,1,1,2,2,1},
					   };
	int x = 7, y = 4, newC = 3;
	floodFill(screen, x, y, newC);

	cout << "Updated screen after floodfill: \n";
	for (int i=0; i<M; ++i)
	{
		for(int j=0; j<N; ++j)
			cout << screen[i][j] << " ";
		cout<< endl;
	}
	return 0;
}
