/*
 * k_queens.cpp
 * write a code to place queens on a chessboard such that no two queens
 * share the same col, row or diag
 *  Created on: May 8, 2015
 *      Author: Athakur
 */

#include <iostream>
#include <math.h>
using namespace std;

void k_queen(int index, int k, int* map)
{
	if (index < k)
	{
		// Start placing queens
		for(int i=1; i<=k; i++)
		{
			map[index] = 1;
			bool flag = true;
			for (int j=0; j<index; ++j)
			{
				if (index-j == abs(map[index]-map[j]) || map[index]==map[j])
				{
					flag=false;
					break;
				}
			}
			if (flag)
			{
				if (index==k)
				{
					for (int m=1; m<=k; ++m)
						cout << map[m] << " ";
				}

				if(index<k)
					k_queen(index+1, k, map);
			}
		}

	}
}

void k_queens(int num_queen)
{
	int *map = new int[num_queen+1];
	k_queen(1,num_queen,map);
}

int main()
{
	k_queens(8);
	return 0;
}
