/*
 * replace_with.cpp
 * Code: replace spaces with %20
 *  Created on: Mar 26, 2015
 *      Author: Athakur
 */

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

char* replace(char* c)
{
	if (c == NULL)
		return NULL; // return NULL for an empty cstring
	int len = strlen(c);
	if (len == 0) // return NULL for an empty cstring
		return NULL;
	int count = 0;
	for(int i=0; i<len; i++)
	{
		if (c[i] == ' ')
			++count; // count the number of whitespaces
	}

	char *cc = new char[len+2*count+1]; // create another array to store the %20, it being 3 chars

	int p=0;
	for(int i=0; i<len;i++)
	{
		if (c[i] == ' ')
		{
			cc[p] = '%';
			cc[p+1] = '2';
			cc[p+2] = '0';
			p+=3;
		}
		else
		{
			cc[p] = c[i];
			++p;
		}
	}
	cc[p] = '\0';
	return cc;

}
int main()
{
	const int i = 100;
	char input[i] = "We fucking lost man";
	char* output = replace(input);
	cout << "The new string is " << output;
	cout << endl;
	return 0;
}
