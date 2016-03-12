#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
typedef multiset<int>::iterator MITER;
typedef pair<MITER,MITER> COUP;
int main()
{
    multiset<int> m;
    m.insert(12);
    m.insert(8);
    m.insert(12);
    m.insert(8);
    m.insert(7);
    m.insert(10);
    m.insert(15);
    m.insert(14);
    m.insert(7);
    m.insert(8);
    m.insert(12);
    m.insert(13);
    m.insert(11);
    m.insert(10);
    m.insert(14);
    m.insert(12);
    m.insert(7);
    m.insert(13);
    m.insert(10);
    m.insert(12);
    m.insert(7);
    m.insert(8);
    m.insert(11);
    m.insert(14);
    int cnt=m.count(12);
    cout<<"12: "<<cnt<<"\n";
    cnt=m.count(7);
    cout<<"7: "<<cnt<<"\n";
    cnt=m.count(8);
    cout<<"8: "<<cnt<<"\n";
    cnt=m.count(10);
    cout<<"10: "<<cnt<<"\n";
    cnt=m.count(14);
    cout<<"14: "<<cnt<<"\n";
    cnt=m.count(11);
    cout<<"11: "<<cnt<<"\n";
    cnt=m.count(13);
    cout<<"13: "<<cnt<<"\n";
    cnt=m.count(15);
    cout<<"15: "<<cnt<<"\n";
    COUP x=m.equal_range(12);
    m.erase(x.first,x.second);
    MITER iter=m.find(12);
    if (iter==m.end()) cout<<"empty"<<"\n";
    system("pause");
    return 0;
}
