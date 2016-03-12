#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<set>
using namespace std;
int main()
{
    set<int> a;
    a.insert(12);
    a.insert(220);
    a.insert(78);
    a.insert(46);
    a.insert(65);
    a.insert(98);
    a.insert(4);
    a.insert(173);
    set<int>::iterator iter1,iterl,iterr;
    iterl=a.begin(); iterr=iterl; iterr++; iterr++; iterr++; iterr++; iterr++;
    iter1=lower_bound(iterl,iterr,8);
    cout<<*iter1<<"\n";
    system("pause");
    return 0;
}
