*
* Power_set.cpp
* Find the set of all subsets in a set.
*  Created on: May 8, 2015
*      Author: Athakur
*/

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

void printPowerSet(char* set, int set_size)
{
	/* set size of power set with the set_size
	 * n is (2**n-1)
	 */
	unsigned int pow_set_size = pow(2, set_size);
	unsigned int counter,j;

	// Run from counter 000..0 to 111..1
	for (counter=0; counter<pow_set_size;counter++)
	{
		// Check if the jth bit is set in the counter. Yes : Print
		for(j=0; j<set_size; j++)
		{
			if (counter & (1<<j))
				cout << set[j] << " ";
		}
		cout << "\n";
	}
}


int main()
{
	char set[] = {'a', 'b', 'c', 'd', 'e'};
	printPowerSet(set,5);
	return 0;
}
