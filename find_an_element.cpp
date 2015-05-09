#include <iostream>

using namespace std;

int search(int a[][3], int start, int end, int x)
{
	int j=0;
		for (int i=0; i<3; i++)
		{
			int mid = (start+end)/2;
			cout << "The value of mid in run " << i << " is " << mid << endl;		
				if (a[mid][j] == x) 
					return a[mid][j];
				else if (x >= a[start][j] && x < a[mid][j])
				{
					end = mid - 1;
					cout << "The value of end in run (" << i  << ", " << j << ") is " << end << endl;
					++j;
				}
				else 
				{
					start = mid + 1;
					cout << "The value of start in run (" << i  << ", " << j << ") is " << start << endl;
					++j;
				}
		}
	return -1;
}

int main()
{
	int a[3][3] = { {1,2,3},
			{4,5,6},
			{7,8,9}
		      };
	cout << search(a, 0, 2, 5) << endl; 
	return 0;
}
