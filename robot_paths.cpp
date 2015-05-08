/*
 * Robot_paths.cpp
 * Given an NxN grid, find all the possible paths for the robot to take
 * Logic: For a given X by Y grid, the number of right moves are X-1 and the number of down moves are Y-1
 * Therefore, total number of moves equals (X-1)+(Y-1), and the possible paths are C(X-1, X-1+Y-1)
 *  Created on: May 4, 2015
 *      Author: Athakur
 */

#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

typedef long long ll;
typedef struct point
{
	int x,y;
}point;

stack<point> sp;
const int MAXN = 20;
int g[MAXN][MAXN];
point vp[MAXN+MAXN];

ll fact(int n)
{
	if (n==0)
		return 1;
	else
		return n*fact(n-1);
}
ll path(ll m, ll n)
{
	return fact(m-1+n-1)/(fact(m-1))*(fact(n-1));
}

bool get_path(int n, int m)
{
	point p;
	p.x=m;
	p.y=n;
	sp.push(p);
	if (n==1 && m==1)
		return true;
	bool suc = false;
	if (m>1 && g[m-1][n])
		suc = get_path(m-1,n);
	if (!suc && n>1 && g[m][n-1])
		suc = get_path(m,n-1);
	if (!suc)
		sp.pop();
	return suc;
}

void print_paths(int m, int n, int M, int N, int len)
{
	if (g[m][n] == 0)
		return;
	point p;
	p.x=m;
	p.y=n;
	vp[len++] = p;
	if (m==M && n==N)
	{
		for (int i=0; i<len; i++)
			cout <<"(" << vp[i].y <<","<<vp[i].x << ")" << " ";
		cout << endl;
	}
	else
	{
		print_paths(m,n+1,M,N,len);
		print_paths(m+1,n,M,N,len);
	}
}

int main()
{
	for (int i=1; i<10; ++i)
		cout << "Number of possible paths are " << path(i,i) << endl;
	cout << endl;

	int M=3, N=4;
	for (int i=1; i<M; i++)
		for (int j=1; j<N; j++)
			cin>>g[i][j];

	cout << "one of the paths:" << endl;
	get_path(M,N);
	while(!sp.empty())
	{
		point p = sp.top();
		cout <<"("<<p.y <<"," << p.x <<")" << " ";
		sp.pop();
	}

	cout<<endl<<"all paths:"<<endl;
	print_paths(1, 1, M, N, 0);
	return 0;
}
