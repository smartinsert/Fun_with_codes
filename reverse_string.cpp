/*
 * reverse_string.cpp
 * reverse a C-Style string
 *  Created on: Mar 25, 2015
 *      Author: Athakur
 */
#include <iostream>
#include <cstring>

using namespace std;

void swap(char &a, char &b)
{
	a = a^b;
	b = a^b;
	a = a^b;
}

void reverse(char* s)
{
	if (!s) return;
	char* p=s, *q=s;
	while(*q)
		q++;
	--q;
	while(p<q)
		swap(*p++,*q--);
}

int main()
{
	char s[] = "1234567890";
	reverse(s);
	cout<< s << endl;
	return 0;
}
