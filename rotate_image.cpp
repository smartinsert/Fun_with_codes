#include <iostream>

using namespace std;

/* Problem Statement: Given an image represented by an NxN matrix, where 
 * each pixel in the images is 4 bytes, write a method to rotate the image by 90 * degrees
 *
 * Relevant Points: Each pixel 4 bytes => int 
 * NxN: 2D integer array
 * rotate by 90 degress: replace the older ones with the rotated ones
 */
void swap(int &a, int &b)
{
/*
	a=a^b;
	b=a^b;
	a=a^b;
*/
	int t=a;
	a=b;
	b=t;
}

void rotate(int **a, int size)
{

	for(int i=0; i<size; i++)
		for(int j=i+1; j<size; j++)
			swap(a[i][j], a[j][i]);
	for(int i=0; i<size/2; i++)
		for(int j=0; j<size; j++)
			swap(a[i][j], a[size-i-1][j]);

}


int main()
{
	int n, p=0;
	cout<< "Enter the matrix size." << "\t";
	cin>>n;
	// Created an array of pointers to an array in heap
	
	int** arr = new int*[n];
	for(int i=0; i<n; ++i)
		arr[i] = new int[n]; // 2D array 
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			arr[i][j] = ++p;
		}
	}

/*	
	int arr[2][2]= {
			{1,2},
			{3,4},
			};	
//	rotate(n);
*/
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout<< endl;
	}
	
	rotate(arr, n);
	cout << "The rotated array is :" << endl;
	for(int i=0; i<n; i++)
        {
                for(int j=0; j<n; j++)
                {
                        cout << arr[i][j] << "\t";
                }
                cout<< endl;
        }

	for(int i=0; i<n; i++)
		delete[] arr[i];
	delete[] arr;
	return 0;
}
