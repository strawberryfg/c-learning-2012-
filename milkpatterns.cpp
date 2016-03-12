#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 80020
#define maxcnt 1000020
using namespace std;
int n,times,fmax,j,k,le,ri,mid,ans,cnt[maxcnt];
int a[maxn],s[maxn],r[maxn],tr[maxn],ts[maxn],h[maxn];
bool check(int x)
{
     int i=2,j,sum;
     for (;i<=n;i=j+1)
     {
        for (;i<=n && h[i]<x;i++); 
        if (i>n) break;
        j=i;
        sum=2;
        if (sum>=times) return true;
        for (;j+1<=n && h[j+1]>=x;j++)
        {
           sum++;
           if (sum>=times) return true;        
        }
     }
     return false;
}
int main()
{
    scanf("%d %d",&n,&times);
    fmax=0;
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]); 
        cnt[a[i]]++;
        fmax=max(fmax,a[i]);
    }
    for (int i=1;i<=fmax;i++) cnt[i]+=cnt[i-1];
    for (int i=n;i>0;i--) s[cnt[a[i]]--]=i;
    r[s[1]]=1; j=1;
    for (int i=2;i<=n;i++) 
    {
        if (a[s[i]]!=a[s[i-1]]) j++;
        r[s[i]]=j;
    }
    k=j; j=1;
    while (k<n)
    {
        memset(cnt,0,sizeof(cnt));
        for (int i=1;i<=n;i++) tr[i]=r[i];
        for (int i=1;i<=n;i++) cnt[r[i+j]]++;
        for (int i=1;i<=n;i++) cnt[i]+=cnt[i-1];
        for (int i=n;i>0;i--) ts[cnt[r[i+j]]--]=i;
        memset(cnt,0,sizeof(cnt));
        for (int i=1;i<=n;i++)
        {
            r[i]=tr[ts[i]];
            cnt[r[i]]++;
        }  
        for (int i=1;i<=n;i++) cnt[i]+=cnt[i-1];
        for (int i=n;i>0;i--) s[cnt[r[i]]--]=ts[i];
        r[s[1]]=1;
        k=1;
        for (int i=2;i<=n;i++)
        {
            if (tr[s[i]]!=tr[s[i-1]] || tr[s[i]+j]!=tr[s[i-1]+j]) k++;
            r[s[i]]=k;
        }
        j*=2;
    }
    j=0; h[1]=0;
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
    le=1; ri=n+1-times;
    while (le<=ri)
    {
        mid=(le+ri)/2;
        if (check(mid)) { ans=mid; le=mid+1; }
           else ri=mid-1;  
    }
    printf("%d\n",ans);
//    system("pause");
    return 0;
}
