#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int a[6];
struct rec
{
    int x;
    int y;
    double z;
    rec(int u,int v,double w):x(u),y(v),z(w){}
    rec(){}
}data[10];
int main()
{
    memset(a,0,sizeof(a));
    for (int i=0;i<6;i++) cout<<a[i]<<" "; 
    printf("\n");
    printf("%d\n",sizeof(a));    
    char s[100]="fsfsdarewafrew";
    //char s[]="fsfsdarewafrew";
    memset(s,'S',4);
    for (int i=0;i<strlen(s);i++) cout<<s[i];
    printf("\n");
    rec data1(423432,77234,989.243);
    cout<<data1.x<<" "<<data1.y<<" "<<data1.z<<"\n";
    memset(&data1,0,sizeof(rec));
    //memset(&data1,0,sizeof(struct rec);
    cout<<data1.x<<" "<<data1.y<<" "<<data1.z<<"\n";
    memset(data,0,sizeof(rec)*10); 
    system("pause");
    return 0;
}
