#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define maxn 70020
#define max 300
typedef int arr[maxn];
using namespace std;
int n,j,k,opt,x,pd;
arr a,r,s,tr,ts,cnt,h,le,ri;
char ch;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ch=getchar();
    while (ch!='\n')
    {
       a[++n]=ch; cnt[a[n]]++;
       ch=getchar();
    }    
    for (int i=1;i<=max;i++) cnt[i]+=cnt[i-1];
    for (int i=n;i>=1;i--)
    {
        s[cnt[a[i]]]=i;
        cnt[a[i]]--;
    }
    r[s[1]]=1; j=1;
    for (int i=2;i<=n;i++)
    {
        if (a[s[i-1]]!=a[s[i]]) j++;
        r[s[i]]=j;
    }
    k=j; j=1;
    while (k<n)
    {
       for (int i=1;i<=n;i++) tr[i]=r[i];
       memset(cnt,0,sizeof(cnt));
       for (int i=1;i<=n;i++) cnt[r[i+j]]++;
       for (int i=1;i<=n;i++) cnt[i]+=cnt[i-1];
       for (int i=n;i>=1;i--)
       {
           ts[cnt[r[i+j]]]=i;
           cnt[r[i+j]]--;
       }
       memset(cnt,0,sizeof(cnt));
       for (int i=1;i<=n;i++)
       {
           r[i]=tr[ts[i]];
           cnt[r[i]]++;
       }
       for (int i=1;i<=n;i++) cnt[i]+=cnt[i-1];
       for (int i=n;i>=1;i--)
       {
           s[cnt[r[i]]]=ts[i];
           cnt[r[i]]--;
       }
       r[s[1]]=1; k=1;
       for (int i=2;i<=n;i++)
       {
           if (tr[s[i-1]]!=tr[s[i]] || tr[s[i-1]+j]!=tr[s[i]+j]) k++;
           r[s[i]]=k;
       }
       j*=2;
    }
    h[1]=0; j=0;
    for (int i=1;i<=n;i++)
    {
        if (r[i]!=1)
        {
           k=s[r[i]-1];
           while (i+j<=n && k+j<=n && a[i+j]==a[k+j]) j++;
           h[r[i]]=j;
           if (j) j--;
        }
    }
    for (int i=1;i<=n;i++) 
    {
        le[i]=ri[i-1]+1; ri[i]=le[i]+n-s[i]+1-h[i]-1;        
    }
    scanf("%d",&opt);
    for (int i=1;i<=opt;i++)
    {
        scanf("%d",&x);
        pd=0;
        for (j=1;j<=n;j++)
        {
            if (le[j]<=x && x<=ri[j])
            {
               pd=1;
               for (k=s[j];k<=s[j]+h[j]-1;k++) cout<<char(a[k]);
               for (k=s[j]+h[j];k<=s[j]+h[j]+x-le[j];k++) cout<<char(a[k]);
               printf("\n");
            }
        }
        if (!pd) printf("-1\n");
    }
//    system("pause");
    return 0;
}
