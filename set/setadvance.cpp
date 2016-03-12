#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<set>
using namespace std;
int main()
{
    multiset<int> a; //4 8 15 16 23 42
    a.insert(42);
    a.insert(15);
    a.insert(16);
    a.insert(8);
    a.insert(23);
    a.insert(4);
    a.insert(15);
    a.insert(15);
    a.insert(42);
    a.insert(4);
    a.insert(23);
    a.insert(4);
    multiset<int>::iterator iter1=a.begin();
    advance(iter1,7);
    cout<<*iter1<<"\n";
    system("pause");
    return 0;
}
