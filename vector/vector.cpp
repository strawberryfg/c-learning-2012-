#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#define pb push_back
using namespace std;
int main()
{
    int ary[5]={0,23,242,987,31};
    vector<int> vec(ary,ary+5);
    vector<int>::reverse_iterator iter=vec.rbegin();
    for (;iter!=vec.rend();iter++) cout<<*iter<<" ";
    iter=vec.rend()-1;
    for (;iter!=vec.rbegin()-1;iter--) cout<<*iter<<" ";
    sort(vec.rbegin(),vec.rend());
    for (int i=0;i<5;i++) cout<<vec[i]<<" ";
    cout<<"\n";
    system("pause");
    return 0;
}
