#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<list>
using namespace std;
int main()
{
    list<int> a,b;
    a.push_back(110);
    a.push_back(40);
    a.push_back(10);
    a.sort(greater<int>());
    b.push_back(95);
    b.push_back(15);
    b.push_back(70);
    b.sort(greater<int>());
    a.merge(b,greater<int>());
    list<int>::iterator iter1=a.begin();
    for (;iter1!=a.end();iter1++) cout<<*iter1<<" ";
    cout<<"\n";
    system("pause");
    return 0;
}
