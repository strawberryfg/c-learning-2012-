#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxm 30020
#define maxq 1000020
#define inf 2147483647
using namespace std;
struct rec
{
   int u,v,nxt,c,op;
}g[maxm];
int n,m,s,t,i,sum,tot,x,y,z;
int a[maxm],edge[maxm],h[maxm],hash[maxm];
int q[maxq];
void addedge(int x,int y,int z)
{
     g[++tot].u=x; g[tot].v=y; g[tot].c=z; g[tot].nxt=edge[x]; edge[x]=tot; g[tot].op=tot+1;
     g[++tot].u=y; g[tot].v=x; g[tot].c=0; g[tot].nxt=edge[y]; edge[y]=tot; g[tot].op=tot-1;
}
int flow(int x,int now)
{
    int tmp,p,res,fmin;
    if (x==t) return now;
    tmp=0; p=edge[x];
    while (p)
    {
          if (g[p].c && h[g[p].v]+1==h[x])
          {
             res=flow(g[p].v,min(g[p].c,now));
             g[p].c-=res; g[g[p].op].c+=res;
             now-=res; tmp+=res;
             if (h[s]==t+1) return tmp;
             if (now==0) break;
          }
          p=g[p].nxt;
    }
    if (!tmp)
    {
       hash[h[x]]--;
       if (!hash[h[x]]) 
       {
          h[s]=t+1;
       }
       else 
       {
          fmin=t;
          p=edge[x];
          while (p)
          {
            if (g[p].c && h[g[p].v]<fmin) fmin=h[g[p].v];
            p=g[p].nxt;
          }      
          h[x]=fmin+1;
          hash[h[x]]++;
       }
    }
    return tmp;
}
void sap()
{
     int head,tail,p;
     for (int i=s;i<=t;i++) h[i]=t+1;
     q[1]=t; h[t]=0;
     head=1; tail=1;
     memset(hash,0,sizeof(hash));
     while (head<=tail)
     {
        p=edge[q[head]];
        while (p)
        {
          if (!g[p].c && h[g[p].v]==t+1)
          {
             h[g[p].v]=h[q[head]]+1;
             q[++tail]=g[p].v;
          }
          p=g[p].nxt;
        }
        head++;
     }
for (int i=s;i<=t;i++) hash[h[i]]++;
while (h[s]<t+1) sum+=flow(s,inf);
}
int main()
{
    freopen("destroy.in","r",stdin);
    freopen("destroy.out","w",stdout);
    scanf("%d %d",&n,&m);
    s=0; t=n+m+1;
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&x,&y,&z);
        addedge(s,i,z);
        addedge(i,m+x,inf);
        addedge(i,m+y,inf);
    }
    for (int i=1;i<=n;i++) addedge(i+m,t,a[i]);
    sap();
    printf("%d\n",sum);
//    system("pause");
    return 0;
}
