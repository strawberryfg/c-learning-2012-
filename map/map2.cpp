#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef map<int,int>::iterator MITER;
typedef map<int,int>::const_iterator CMITER;
int main()
{
    map<int,int> m;
    m[0]=1; m[1]=2; m[4]=10; m[7]=8;
    cout<<m[5]<<"\n";
    cout<<m[1]<<"\n";
    MITER iter1=m.find(4);
    if (iter1!=m.end()) cout<<iter1->first <<" "<<iter1->second <<"\n";
    iter1->second =8;
    cout<<iter1->second <<"\n";
    CMITER iter2=m.find(7);
    //iter2->second =15;
    cout<<iter2->second <<"\n";
    
    map<int,int> m1;
    m1[1]=1;
    m1[3]=3;
    m1[5]=5;
    m1[8]=8;
    m1[10]=10;
    MITER iter=m1.lower_bound(4);
    cout<< iter->first <<" "<< iter->second <<" "<<"\n";
    iter=m1.lower_bound(3);
    cout<< iter->first <<" "<< iter->second <<" "<<"\n";
    iter=m1.upper_bound(5);
    cout<< iter->first <<" "<< iter->second <<" "<<"\n";
    system("pause");
    return 0;
}
