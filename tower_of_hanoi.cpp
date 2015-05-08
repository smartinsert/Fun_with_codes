/*
 * Tower_of_Hanoi.cpp
 * Move the disk from one tower to the other in an ascending order
 *  Created on: Apr 15, 2015
 *      Author: Athakur
 */

#include <iostream>
#include <stack>

using namespace std;

struct toh
{
	int begin, end;
	char src, mid, dst;
	toh (int pbegin, int pend, char csrc, char cmid, char cdst) : begin(pbegin), end(pend), src(csrc), mid(cmid), dst(cdst) {}
};

void hanoi(int n, char src, char mid, char dst)
{
	stack<toh> obj;
	obj.push(toh(1,n,src, mid, dst));
	toh tmp(1,n,src,mid,dst);
	while(!obj.empty())
	{
		tmp = obj.top();
		obj.pop();
		if (tmp.begin != tmp.end)
		{
			obj.push(toh(tmp.begin, tmp.end-1, tmp.mid, tmp.src, tmp.dst));
			obj.push(toh(tmp.end, tmp.end, tmp.src, tmp.mid, tmp.dst));
			obj.push(toh(tmp.begin, tmp.end, tmp.src, tmp.dst, tmp.mid));
		}

		else
		{
			cout << "Move disk " << tmp.begin << " " << tmp.mid << " " << tmp.end;
			cout << endl;
		}
	}
}
int main()
{
	int n=3;
	hanoi(n, 'A', 'B', 'C');
	return 0;
}
