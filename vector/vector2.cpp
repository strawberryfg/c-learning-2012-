#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int ary[5]={132,14,89,-20,31};
    vector<int> vec(ary,ary+5);
    vec.erase(vec.begin()+1,vec.begin()+4);
    vector<int>::iterator iter=vec.begin();
    for (;iter!=vec.end();iter++) cout<<*iter<<" ";
    cout<<"\n";
    vec.insert(vec.begin()+1,4,2);
    vector<int>::iterator iter1=vec.begin();
    for (;iter1!=vec.end();iter1++) cout<<*iter1<<" ";
    cout<<"\n";    
    iter1=vec.begin()+2;
    vec.insert(iter1,125);
    vec.pop_back();
    iter1=vec.begin();
    for (;iter1!=vec.end();iter1++) cout<<*iter1<<" ";
    cout<<"\n";     
    vector<int> vec2;
    vec2=vec;
    vec.insert(vec.begin()+2,vec2.begin(),vec2.begin()+3);
    iter1=vec.begin();
    for (;iter1!=vec.end();iter1++) cout<<*iter1<<" ";
    cout<<"\n";     
    vector<int> vec3(vec.begin()+2,vec.begin()+5);
    iter1=vec3.begin();
    for (;iter1!=vec3.end();iter1++) cout<<*iter1<<" ";    
    cout<<"\n";
    system("pause");
    return 0;
}
