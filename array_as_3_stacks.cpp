/*
 * array_as_3_stacks.cpp
 * Implement an array as 3 stacks
 *  Created on: Apr 14, 2015
 *      Author: Athakur
 */

#include <iostream>

using namespace std;

class stack3
{
	int *buf;
	int ptop[3];
	int size;

public:
	stack3(int size=300)
{
	buf = new int[size*3];
	ptop[0] = ptop[1] = ptop[2] = -1;
	this->size = size;
}

	void push(int StackNum, int value)
	{
		int idx = (StackNum-1)*size + ptop[StackNum-1] + 1;
		buf[idx] = value;
		++ptop[StackNum-1];
	}

	void pop(int StackNum)
	{
		--ptop[StackNum-1];
	}

	int top(int StackNum)
	{
		int idx = (StackNum-1)*size + ptop[StackNum-1];
		return buf[idx];
	}

	bool IsEmpty(int StackNum)
	{
		return ptop[StackNum-1] == -1;
	}
};

int main()
{
	stack3 stack;
	    for(int i=0; i<10; ++i)
	        stack.push(1, i);
	    for(int i=10; i<20; ++i)
	        stack.push(2, i);
	    for(int i=100; i<110; ++i)
	        stack.push(3, i);
	    for(int i=0; i<3; ++i)
	        cout<<stack.top(i+1)<<" ";

	    cout<<endl;
	    for(int i=0; i<3; ++i){
	        stack.pop(i+1);
	        cout<<stack.top(i+1)<<" ";
	    }

	    cout << endl;
	    stack.push(1, 111);
	    stack.push(2, 222);
	    stack.push(3, 333);
	    for(int i=0; i<3; ++i)
	        cout<<stack.top(i+1)<<" ";
	    return 0;
}
