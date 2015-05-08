/*
 * Duplicate.cpp
 * Code to remove duplicate characters
 *  Created on: Mar 26, 2015
 *      Author: Athakur
 */

#include <iostream>

using namespace std;

string duplicate(string s)
{
	int len = s.length();
	if (len < 2)
		return s;
	string str = "";
	for(int i=0; i<len; ++i)
	{
		if (s[i] != '\0')
		{
			str+=s[i];
			for(int j=i+1; j<len;++j)
			{
				if (s[j] == s[i])
					s[j] = '\0';
			}
		}
	}
	return str;
}


int main()
{
	string s = "aaabbbbcde";
	string new_str = duplicate(s);
	cout << "The new string is " << new_str << endl;
	return 0;
}

