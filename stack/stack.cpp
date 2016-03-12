#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
int main()
{
    stack<int> a;
    a.push(32);
    a.push(4325);
    a.push(9897);
    a.pop();
    cout<<a.top()<<"\n";
    a.push(83254);
    a.push(145875);
    a.push(998);
    stack<int> b=a;
    while (!a.empty()) 
    {
       cout<<a.top()<<" ";
       a.pop();
    }   
    cout<<"\n";
    while (b.size())
    {
       cout<<b.top()<<" ";
       b.pop();
    }
    cout<<"\n";
    system("pause");
    return 0;
}
