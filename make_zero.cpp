/*
 * make_zero.cpp
 * Algorithm to make all the value zero in a column wherever there is a zero
 *  Created on: Mar 30, 2015
 *      Author: Athakur
 */
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

void zero(int **a, int m, int n)
{
	bool row[m], col[n];
	memset(row, false, sizeof(row));
	memset(col, false, sizeof(col));
	for(int i=0; i<m; ++i)
		for(int j=0; j<n; ++j)
			if(a[i][j] == 0)
			{
				row[i] = true;
				col[j] = true;
			}
	for(int i=0; i<m; ++i)
		for(int j=0; j<n; ++j)
			if (row[i] || col[j])
				a[i][j]=0;
}

int main()
{
	freopen("1.7.in", "r", stdin);

	int m,n;
	cin>>m>>n;

	int **a;
	a = new int* [m];
	for (int i=0; i<m; i++)
		a[i] = new int [n];
	for(int i=0; i<m; ++i)
		for(int j=0; j<n; ++j)
		{
			cout << "Enter the (" << i << "," << j << ")th element of the 2D array:";
			cin>>a[i][j];
			cout<< endl;
		}

	for(int i=0; i<m; ++i)
	{
	    for(int j=0; j<n; ++j)
	        cout<<a[i][j]<<" ";
	    cout<<endl;
	}
	cout<< endl;

	zero(a,m,n);

	for(int i=0; i<m; ++i)
	{
		for(int j=0; j<n; ++j)
			cout<<a[i][j]<< " ";
		cout << endl;
	}

	fclose(stdin);
	return 0;
}
