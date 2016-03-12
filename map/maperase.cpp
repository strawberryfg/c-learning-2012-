#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<map>
using namespace std;
int main()
{
    map<int,int> m;
    m[1]=4;
    m[3]=7;
    m[5]=10;
    m[7]=14;
    m[8]=19;
    m[9]=30;
    map<int,int>::iterator iter1,iter2;
    iter1=m.find(5);
    m.erase(iter1);
    iter1=m.find(1);
    iter2=m.find(7);
    m.erase(iter1,iter2);
    m.erase(8);
    cout<<m.size()<<"\n";
    system("pause");
    return 0;
}
