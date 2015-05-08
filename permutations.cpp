/*
 * permutations.cpp
 * Recursive method to write all permutations of a string
 *  Created on: May 8, 2015
 *      Author: Athakur
 */


#include <iostream>

using namespace std;

// swap two chars
void swap(char* a, char* b)
{
	char temp;
	temp = *a;
	*a=*b;
	*b=temp;
}

/* Function to print permutations of string
 * This function takes three parameters:
 * 1. String
 * 2. Starting index of the string
 * 3. Ending index of the string.
 */
void permute(char* a, int i, int n)
{
	int j;
	if (i==n)
		cout << a << "\n";
	else
	{
		for (j=i; j<=n; j++)
		{
			swap(a+i, a+j);
			permute(a, i+1, n);
			swap(a+i, a+j); // backtracking
		}
	}
}


int main()
{
	char a[] = "ABCD";
	permute(a,0,3);
	return 0;
}
