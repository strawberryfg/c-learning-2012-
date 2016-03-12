#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
template<class T,int size>
T getsum(T (&arr)[size])
{
    int ret=0;
    for (int i=0;i<size;i++) ret+=arr[i];
    return ret;
}
char s[320];
template<int size> char * getsum(char * (&arr)[size])
{
    int n=0;
    for (int i=0;i<size;i++) n+=strlen(arr[i]);
    cout<<strlen(arr[0])<<" "<<strlen(arr[1])<<" "<<strlen(arr[2])<<endl;
    char * ret=s;
    ret[0]='\0';
    for (int i=0;i<size;i++) 
    {
        cout<<ret<<endl;
        strcat(ret,arr[i]);
    }
    return ret;
}
char a[3][100];
int main()
{
    char ch;
    a[0][0]='\0'; a[1][0]='\0'; a[2][0]='\0';
    for (int i=0;i<3;i++)
    {
        int j=0;
        ch=getchar();
        while (ch!='\n'/* && ch!='\r'*/) //可加可不加 
        {
           a[i][j]=ch;
           ch=getchar();
           j++;
        }
    }    
    char * b[3];
    b[0]=&a[0][0];   //b[0]=a[0];
    b[1]=&a[1][0];   //b[1]=a[1];
    b[2]=&a[2][0];   //b[2]=a[2];
//    cout<<b[0]<<" "<<b[1]<<" "<<b[2]<<endl;
    cout<<getsum(b)<<endl;
    int c[5]={423,354,77,16,98};
    cout<<getsum(c)<<endl;
    system("pause");
    return 0;                    
}
