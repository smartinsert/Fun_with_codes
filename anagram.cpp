/*
 * Anagram.cpp
 * Code: Detect if two strings are anagrams
 *  Created on: Mar 26, 2015
 *      Author: Athakur
 */
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool isAnagram(string &s, string &t)
{
	if (s == "" || t == "")
		return false;

	// remove whitespace characters
	s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());
	t.erase(remove_if(t.begin(), t.end(), ::isspace), t.end());

	if (s.length() != t.length())
		return false;

	// Check for case difference and turn the whole string to lower case
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	transform(t.begin(), t.end(), t.begin(), ::tolower);

	int len = s.length();
	int c[256];
	memset(c,0,sizeof(c));
	for(int i=0; i<len; i++)
	{
		++c[(int)s[i]];
		--c[(int)t[i]];
	}

	for(int i=0; i<256; i++)
	{
		if (c[i] != 0)
			return false;
	}

	return true;
}

int main()
{
	string a = "dormitory";
	string b = "dirty room";
	bool result = isAnagram(a,b);
	if (result)
		cout << "The strings are anagrams.";
	else
		cout << "The strings are not anagrams.";

	//cout << result?"The strings are anagram":"The strings are not anagram";
	cout<< endl;
	return 0;
}
