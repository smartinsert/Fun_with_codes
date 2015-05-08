/*
 * Fibonacci.cpp
 * Generate a fibonacci sequence using recursion
 *  Created on: May 4, 2015
 *      Author: Athakur
 */

#include <iostream>

using namespace std;

typedef long long ll;

ll compute(ll n)
{
	// Base Case: Start from 1
	if (n<1)
		return -1;

	if (n==1 || n==2)
		return 1;
	else
		return compute(n-1) + compute(n-2);
}


int main()
{
	for (int i=1; i<20; ++i)
		cout << compute(i) << " ";
	cout << endl;
	return 0;
}
