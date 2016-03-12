#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#define VITER vector<int>::iterator
using namespace std;
int main()
{
    vector<int> a;
    a.push_back(123);
    a.push_back(5);
    a.push_back(4);
    a.push_back(43);
    a.push_back(43);
    a.push_back(75);
    a.push_back(5);
    a.push_back(5);
    a.push_back(6);
    a.push_back(22);
    a.push_back(123);
    a.push_back(4);
    sort(a.begin(),a.end());
    VITER iter=unique(a.begin(),a.end());
    int n=iter-a.begin();
    cout<<n<<"\n";
    VITER iter1=a.begin();
    for (;iter1!=a.end();iter1++) cout<<*iter1<<" ";
    cout<<"\n";
    a.erase(iter,a.end());
    iter1=a.begin();
    for (;iter1!=a.end();iter1++) cout<<*iter1<<" ";
    cout<<"\n";
    system("pause");
    return 0;
}
