#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<map>
using namespace std;
int main()
{
    multimap<int,int> a; //4 8 15 16 23 42
    a.insert(make_pair(42,42));
    a.insert(make_pair(15,15));
    a.insert(make_pair(16,16));
    a.insert(make_pair(8,8));
    a.insert(make_pair(23,23));
    a.insert(make_pair(4,4));
    a.insert(make_pair(15,15));
    a.insert(make_pair(15,15));
    a.insert(make_pair(42,42));
    a.insert(make_pair(4,4));
    a.insert(make_pair(23,23));
    a.insert(make_pair(4,4));
    multimap<int,int>::iterator iter1=a.begin();
    advance(iter1,7);
    cout<<iter1->second <<"\n";
    system("pause");
    return 0;
}
