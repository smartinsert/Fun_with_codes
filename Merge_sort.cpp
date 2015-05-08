/*
 * Merge_Sort.cpp
 * Merge array B in A with sufficient space for the former
 *  Created on: Apr 17, 2015
 *      Author: Athakur
 */

#include <iostream>

using namespace std;

void merge(int a[], int b[], int n,int m)
{
	int k = n+m-1;
	int i = n-1;
	int j = m-1;

	while (i>=0 && j>=0)
	{
		if (a[i] > b[j])
			a[k--] = a[i--];
		else
			a[k--] = b[j--];
	}

	while (j>=0)
		a[k--] = b[j--];
}

int main()
{
	int a[15] = {1,3,7,8,9};
	int b[] = {2,4,5,6,10};
	int n=5, m=5;
	merge(a,b,n,m);
	for(int i=0; i<n+m; ++i)
		cout << a[i] << "\t";
	cout<<endl;
	return 0;
}
