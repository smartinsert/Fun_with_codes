#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 100;

struct person
{
	int h, w;
	person() : h(0), w(0) {}
};

person p[maxn];
int d[maxn];

bool cmp(person p, person q)
{
	if (p.h == q.h)
		return p.w < q.w;
	else 
		return p.h < q.h;
}

int pile(person p[], int n)
{
	int k = 1;
	d[0] = p[0].w;
	for (int i=0; i<n; ++i)
	{
		if (p[i].w > d[k-1]) 
			d[k++] = p[i].w;
		else
		{
			int j;
			for (int j=k-1; j>=0 && d[j] > p[i].w; --j)
				d[j+1] = p[i].w;
		}
	}
	return k;
}

int main()
{
	int n;
	cin>>n;
	for (int i=0; i<n; i++)
	{
		cout << "Enter the (h,w) of the " << i+1 << " pair" << endl;
		cin>>p[i].h>>p[i].w;
	}
	sort(p, p+n, cmp);
	cout << pile(p,n) << endl;
	return 0;
}
