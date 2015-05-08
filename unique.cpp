/*
 * Unique.cpp
 * Determine if a string has all unique characters
 *  Created on: Mar 25, 2015
 *      Author: Athakur
 */

#include <iostream>

using namespace std;

bool isUnique(string s)
{
	bool a[256];
	int len = s.length();
	for(int i=0; i<len; i++)
	{
		int v = (int)s[i];
		if (a[v])
			return false;
		a[v] = true;
	}
	return true;
}

int main()
{
	string s = "I am Groot";
	bool result = isUnique(s);
	//cout<< result?"The string is unique":"The string is not unique";
	if(result)
		cout<<"The string is unique"<<endl;
	else
		cout<<"The string is not unique"<<endl;
	return 0;
}
