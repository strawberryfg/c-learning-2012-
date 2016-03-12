#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std; 
int n,num,t,i,j;
long long sum,now,res;
int spe[1001];
struct node
{
       int x[1001];
}f[100001];
char ch;
bool cmp(node a,node b)
{
     if (a.x[0]<b.x[0]) return true;
     if (a.x[0]>b.x[0]) return false;
     for (int i=1;i<=a.x[0];i++)
     {
         if (a.x[i]<b.x[i]) return true;
         if (a.x[i]>b.x[i]) return false;
     }
     return false;
}
void gj()
{
     int t[1001];
     for (int i=1;i<=f[1].x[0];i++) t[i+1]=f[1].x[i];
     t[0]=f[1].x[0];
     t[f[1].x[0]+1]=t[f[1].x[0]+1]+1;
     for (int i=f[1].x[0]+1;i>=2;i--)
     {
         if (t[i]/10>=1)
         {
            t[i-1]+=t[i]/10;
            t[i]%=10;
         }
         else break;
     }
     if (t[1]==0) 
     {
        for (int i=1;i<=f[1].x[0];i++) f[1].x[i]=t[i+1];
     }
     else 
     { 
          for (int i=1;i<=f[1].x[0]+1;i++)
          { 
             f[1].x[i]=t[i]; 
             f[1].x[0]=f[1].x[0]+1; 
          } 
     }
}
int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    scanf("%d",&n);
    ch=getchar();
    for (int i=1;i<=n;i++)
    {
        sum=0;
        ch=getchar();
        while (ch!=' ' && ch!=EOF && ch!='\n')
        {
              f[i].x[0]=++sum;
              f[i].x[sum]=ch-'0';
              ch=getchar();
        }
    }
    spe[0]=1;
    for (int i=1;i<=32;i++) spe[i]=spe[i-1]*10%999983;
    sort(f+1,f+n+1,cmp);
    gj();
    sum=1;
    now=1;
    for (int i=1;i<=n;i++)
    {
        num=0;
        for (j=1;j<=f[i].x[0];j++)
        {
            t=f[i].x[0]-j;
            res=(long long)f[i].x[j]*(long long)spe[t];
            res%=999983;
            num+=res;
        }
        sum=(long long)sum*(long long)num;
        sum%=999983;
    }
    printf("%I64d\n",sum);
    return 0;
}
