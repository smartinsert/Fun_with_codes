/*
 * Set_Of_Stacks.cpp
 * Implement a data structure to switch to a new stack if one is full
 *  Created on: Apr 15, 2015
 *      Author: Athakur
 */

#include <iostream>

using namespace std;

const int STACK_SIZE = 100;
const int STACK_NUM = 10;

class stack
{
	int *buf;
	int cur;
	int capacity;

public:
	stack(int capa = STACK_SIZE)
{
		buf = new int[capa];
		cur = -1;
		capacity = capa;
}

	~stack()
	{
		delete[] buf;
	}
	void push(int val)
	{
		buf[++cur] = val;
	}

	void pop()
	{
		--cur;
	}

	int top()
	{
		return buf[cur];
	}

	bool IsEmpty()
	{
		return (cur == -1);
	}

	bool IsFull()
	{
		return (cur == capacity-1);
	}
};

class SetOfStacks
{
private:
	stack *st;
	int cur;
	int capacity;

public:
	SetOfStacks(int capa = STACK_NUM)
{
		st = new stack[capa];
		cur = 0;
		capacity = capa;
}

	~SetOfStacks()
	{
		delete[] st;
	}

	void push(int val)
	{
		if (st[cur].IsFull())
			++cur;
			st[cur].push(val);
	}

	void pop()
	{
		if(st[cur].IsEmpty())
			--cur;
		st[cur].pop();
	}

	int top()
	{
		if (st[cur].IsEmpty())
			--cur;
		return st[cur].top();
	}

	bool IsFull()
	{
		if (cur == capacity-1)
			return st[cur].IsFull();
		else
			return false;
	}

	bool IsEmpty()
	{
		if (cur==0)
			return st[0].IsEmpty();
		else
			return false;
	}
};

int main()
{
	SetOfStacks* obj = new SetOfStacks;
	for(int i=0; i<3*STACK_SIZE+1; ++i)
		obj->push(i);
	while (!obj->IsEmpty())
	{
		cout << obj->top() << endl;
		obj->pop();
	}

	delete obj;
	return 0;
}
