/*
 * min_in_order_one.cpp
 * Implement min function along with push, pop in O(1).
 *  Created on: Apr 14, 2015
 *      Author: Athakur
 */

#include <iostream>

using namespace std;

const int MAX_INT = ~(1<<31); /// 2147483647

struct node
{
	int val;
	int min;
	node() : val(0), min(0) {}
};

class StackWithMin
{
	node* buf;
	int cur;

public:
	StackWithMin(int size=1000)
	{
		buf = new node[size];
		buf[0].min = MAX_INT;
		cur =0;
	}

	~StackWithMin()
	{
		delete[] buf;
	}

	void push(int val)
	{
		buf[++cur].val = val;
		if (val<buf[cur-1].min)
			buf[cur].min = val;
		else
			buf[cur].min = buf[cur-1].min;
	}

	void pop()
	{
		--cur;
	}

	int top()
	{
		return buf[cur].val;
	}

	bool IsEmpty()
	{
		return cur==0;
	}

	int min()
	{
		return buf[cur].min;
	}
};

int main()
{
	StackWithMin mystack;
	for(int i=0; i<20; ++i)
		mystack.push(i);
	cout<<mystack.min()<<" "<<mystack.top()<<endl;
	mystack.push(-100);
	mystack.push(-100);
	cout<<mystack.min()<<" "<<mystack.top()<<endl;
	mystack.pop();
	cout<<mystack.min()<<" "<<mystack.top()<<endl;
	return 0;
}
