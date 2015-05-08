/*
 * balanced_paranthesis.cpp
 * Write a method to find all the valid combinations of n parentheses
 *  Created on: May 8, 2015
 *      Author: Athakur
 */

#include <iostream>

#define MAX_SIZE 100

using namespace std;

void _printParanthesis(int pos, int n, int open, int close);

// Wrapper around _printParanthesis()

void printParanthesis(int n)
{
	if (n>0)
		_printParanthesis(0,n,0,0);
	return;
}

void _printParanthesis(int pos, int n, int open, int close)
{
	static char str[MAX_SIZE];

	if (close == n)
	{
		cout << str << "\n";
		return;
	}

	else
	{
		if (open>close)
		{
			str[pos] = '}';
			_printParanthesis(pos+1, n, open, close+1);
		}

		if (open<n)
		{
			str[pos] = '{';
			_printParanthesis(pos+1, n, open+1, close);
		}
	}
}

int main()
{
	int n=4;
	printParanthesis(n);
	return 0;
}
