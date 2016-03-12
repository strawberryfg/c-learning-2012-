#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<vector>
#include<list>
using namespace std;
int main()
{
    int ary1[5]={23,19,-12,98,17};
    list<int> a(ary1,ary1+5);   
    int ary2[5]={17,97,1433,432,-13};
    list<int> b(ary2,ary2+5);
    list<int>::iterator iter=a.begin();
    iter++;
    list<int>::iterator iter1=b.begin();
    iter1++; 
    list<int>::iterator iter2=iter1;
    iter2++;
    iter2++;
    a.splice(iter,b,iter1,iter2);
    //a.splice(iter,b,iter1) 只把iter1位置的元素移动 
    list<int>::iterator ite=a.begin();
    for (;ite!=a.end();ite++) cout<<*ite<<" ";
    cout<<"\n";
    ite=b.begin();
    for (;ite!=b.end();ite++) cout<<*ite<<" ";
    cout<<"\n";
    system("pause");
    return 0;
}
