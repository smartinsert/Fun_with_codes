/*
 * sort_anagram_strings.cpp
 * Sort a string array such that all the anagrams appear together
 *  Created on: Apr 17, 2015
 *      Author: Athakur
 */

#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(string s1, string s2)
{
	sort(&s1[0], &s1[0]+s1.length());
	sort(&s2[0], &s2[0]+s2.length());

	return s1 < s2;
}

int main()
{
	string arr[] = {"axyz", "abc", "yzax", "bac", "zyxa", "fg", "gf"};
	sort(arr, arr+7, cmp);
	for(int i=0; i<7; ++i)
		cout << arr[i] << " ";
	return 0;
}
