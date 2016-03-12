#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    vector<int> c;
    c.push_back(10);
    c.push_back(110);
    c.push_back(40);
    sort(c.rbegin(),c.rend()); 
    vector<int>::iterator iter=c.begin();
    for (;iter!=c.end();iter++) cout<<*iter<<" ";
    cout<<"\n";
    system("pause");
    return 0;
}
