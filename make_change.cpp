/*
 * make_change.cpp
 * Given quarter(25), dimes(10), nickel(5) and penny(1), write a code to represent n cents
 *  Created on: May 8, 2015
 *      Author: Athakur
 */

#include <iostream>
#include <list>

using namespace std;

const int arr[]={1,2,3,4};

void find_combine(int &currsum, int tar,list<int> &subset,list<list<int> > &res,int index)
{
    if (tar==currsum)
    {
        res.push_back(subset);
        return;
    }
    if (tar<=currsum)
        return;
    for(int i=index;i<4;++i)
    {
        subset.push_back(arr[i]);
        currsum+=arr[i];
        find_combine(currsum, tar, subset, res,i);
        currsum-=arr[i];
        subset.pop_back();
    }

}

list<list<int> > find_ways(int tar)
{
    int currsum=0;
    list<list<int> > res;
    list<int> subset;
    int index=0;
    find_combine(currsum, tar, subset, res, index);
    return res;
}

void print_out(list<list<int> > a){
    list<list<int> > :: iterator it;
    list<int>::iterator ii;
    int count=1;
    for (it=a.begin(); it!=a.end(); ++it) {
        cout<<"Way "<<count++<<": ";
        for (ii=(*it).begin(); ii!=(*it).end(); ++ii) {
            cout<<*ii<<" ";
        }
        cout<<endl;
    }
}
int main(){
    list<list<int> > res;
    int tar=30;
    cout << "Target Sum = " << tar << endl;
    res=find_ways(tar);
    print_out(res);
    return 0;
}
