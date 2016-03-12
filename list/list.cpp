#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    int ary[5]={4324,432,665,133,78};
    int ary2[7]={1,2,4,6,7,8,3};
    list<int> a(ary,ary+5);
    list<int> b(a);
    vector<int> c(ary2,ary2+7);
    list<int> d(c.begin()+2,c.begin()+6);
    list<int>::iterator iter=d.begin();
    for (;iter!=d.end();iter++) cout<<*iter<<" ";
    cout<<"\n";
    a.pop_front();                                                                                                                                                        
    a.push_front(213);
    iter=a.begin();
    for (;iter!=a.end();iter++) cout<<*iter<<" ";
    cout<<"\n"; 
    iter=a.begin();      
//    a.insert(iter,2,4); 插入2个14 
//    a.insert(iter,13);  插入元素值为13 
    a.insert(iter,c.begin()+2,c.begin()+5); //插入迭代器区间 
    iter=a.begin();
    for (;iter!=a.end();iter++) cout<<*iter<<" ";
    cout<<"\n";
    c.insert(c.begin()+2,a.begin(),a.end());
    vector<int>::iterator iter1=c.begin();
    for (;iter1!=c.end();iter1++) cout<<*iter1<<" ";
    cout<<"\n";
    vector<int> e(c.begin()+1,c.begin()+5); 
    iter1=e.begin();
    for (;iter1!=e.end();iter1++) cout<<*iter1<<" ";
    cout<<"\n";
    vector<int> f(a.begin(),a.end());
    iter1=f.begin();
    for (;iter1!=f.end();iter1++) cout<<*iter1<<" ";
    cout<<"\n";    
    a.sort();
    a.reverse();
    a.unique(); //相邻元素值相等 只保留这些元素的第一个 
    iter=a.begin();
    for (;iter!=a.end();iter++) cout<<*iter<<" ";
    cout<<"\n";
    cout<<a.front()<<" "<<a.back()<<" \n";
    cout<<*a.begin()<<" "<<*(--a.end())<<" \n";
    swap(c,e);
    system("pause");
    return 0;
}
