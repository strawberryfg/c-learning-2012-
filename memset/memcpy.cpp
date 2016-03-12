#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int a[100],b[50];
int main()
{
    char *s="Golden Global View";
    char d[100];
    memcpy(d,s+14,4);
    //memcpy(d,s+14*sizeof(char),4*sizeof(char));
    printf("%s\n",d);
    for (int i=0;i<100;i++) a[i]=i*32+981;
    memcpy(b+10,a+2,34*sizeof(int));
    for (int i=0;i<50;i++) printf("%d ",b[i]);
    printf("\n");    
    system("pause");
    return 0;
}
