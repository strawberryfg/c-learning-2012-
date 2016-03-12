#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define mo 10000
#define maxx 1000
using namespace std;
struct bigint
{
   int data[maxx+1];
   int len;
   bigint operator + (const bigint &y)
   {
      int tmp=max(len,y.len);
      bigint c;
      memset(c.data,0,sizeof(c.data));
      for (int i=0;i<=tmp;i++)
      {
          c.data[i]+=data[i]+y.data[i];
          c.data[i+1]+=c.data[i]/mo;
          c.data[i]%=mo;
      }
      if (c.data[tmp+1]) tmp++;
      c.len=tmp;
      return c;
   }
   bigint operator - (const bigint &y)
   {
      int tmp=max(len,y.len);
      bigint c;
      memset(c.data,0,sizeof(c.data));
      for (int i=0;i<=tmp;i++)
      {
          c.data[i]+=data[i]-y.data[i];
          if (c.data[i]<0)
          {
             c.data[i+1]--;
             c.data[i]+=mo;
          }
      }
      if (!c.data[tmp]) tmp--;
      c.len=tmp;
      return c;
   }
   
}f[21],tf[21];
int n,k;
void print(const bigint &x)
{
     printf("%d",x.data[x.len]);
     for (int i=x.len-1;i>=0;i--) printf("%04d",x.data[i]);
     printf("\n");
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%d %d",&n,&k);
    bigint spe; spe.len=0; spe.data[0]=1;
    for (int i=1;i<=k-1;i++) f[i]=f[i-1]+spe;
    for (int i=2;i<=n;i++)
    {
        for (int j=0;j<=20;j++)
        {
            tf[j].len=f[j].len;
            for (int u=0;u<=f[j].len;u++) tf[j].data[u]=f[j].data[u];
        }
        memset(f,0,sizeof(f));
        f[0]=f[0]+(tf[k-1]-tf[0]);
        for (int j=1;j<=k-1;j++) f[j]=f[j-1]+(f[j]+tf[k-1]);
    }
    print(f[k-1]);
//    system("pause");
    return 0;
}
