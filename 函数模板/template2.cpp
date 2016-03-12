#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
template<class T,int size>
T min(T (&arr)[size])
{
   T fmin=arr[0];
   for (int i=1;i<size;i++) if (arr[i]<fmin) fmin=arr[i];
   return fmin;
}
int main()
{
    typedef int (*spe)(int (&)[3]);
    spe spe1=min;
    int a[3]={5,3,9};
    cout<<spe1(a)<<endl;
    system("pause");
    return 0;
}
