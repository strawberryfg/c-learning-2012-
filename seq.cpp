#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 400000
#define LL long long
using namespace std;
struct rec
{
   int l,r;
   LL del,mul,sum;
}tree[4*maxn];
int n,ch,opt,ll,rr,v;
LL ans,p;
LL a[maxn];
void init(int f,int t,int x)
{
     tree[x].l=f; tree[x].r=t;
     tree[x].mul=1;
     if (f==t)
     {
        tree[x].sum=a[f] % p;
        return;
     }
     init(f,(f+t)/2,x*2);
     init((f+t)/2+1,t,x*2+1);
     tree[x].sum=(tree[x*2].sum+tree[x*2+1].sum) % p;
}
void lazy(int x)
{
     if (tree[x].del || tree[x].mul!=1)
     {
        if (tree[x].l==tree[x].r)
        {
           tree[x].del=0; tree[x].mul=1;
           return;
        }
        tree[x*2].mul=tree[x*2].mul*tree[x].mul % p;
        tree[x*2].del=((tree[x*2].del*tree[x].mul) % p+tree[x].del) % p;
        tree[x*2].sum=((tree[x*2].sum*tree[x].mul) % p+tree[x].del*(tree[x*2].r-tree[x*2].l+1) % p) % p;
        tree[x*2+1].mul=tree[x*2+1].mul*tree[x].mul % p;
        tree[x*2+1].del=((tree[x*2+1].del*tree[x].mul) % p+tree[x].del) % p;
        tree[x*2+1].sum=((tree[x*2+1].sum*tree[x].mul) % p+tree[x].del*(tree[x*2+1].r-tree[x*2+1].l+1) % p) % p;
        tree[x].del=0;
        tree[x].mul=1;        
     }
}
void add(int f,int t,int x,LL v)
{
     int mid;
     if (f<=tree[x].l && tree[x].r<=t)
     {
        tree[x].del=(tree[x].del+v) % p;
        tree[x].sum=(tree[x].sum+v*(tree[x].r-tree[x].l+1) % p) % p;
        return;
     }
     lazy(x);
     mid=(tree[x].l+tree[x].r)/2;
     if (f<=mid) add(f,t,x*2,v);
     if (t>mid) add(f,t,x*2+1,v);
     tree[x].sum=(tree[x*2].sum+tree[x*2+1].sum) % p;
}
void mul(int f,int t,int x,LL v)
{
     int mid;
     if (f<=tree[x].l && tree[x].r<=t)
     {
        tree[x].del=(tree[x].del*v) % p;
        tree[x].mul=(tree[x].mul*v) % p;
        tree[x].sum=(tree[x].sum*v) % p;
        return;
     }
     lazy(x);
     mid=(tree[x].l+tree[x].r)/2;
     if (f<=mid) mul(f,t,x*2,v);
     if (t>mid) mul(f,t,x*2+1,v);
     tree[x].sum=(tree[x*2].sum+tree[x*2+1].sum) % p;
}
LL query(int f,int t,int x)
{
   int mid;
   LL res;
   lazy(x);
   if (f<=tree[x].l && tree[x].r<=t)
   {
      return tree[x].sum % p;
   }
   mid=(tree[x].l+tree[x].r)/2;
   res=0;
   if (f<=mid) res=(res+query(f,t,x*2)) % p;
   if (t>mid) res=(res+query(f,t,x*2+1)) % p;
   tree[x].sum=(tree[x*2].sum+tree[x*2+1].sum) % p;
   return res % p;
}
int main()
{
    freopen("seq.in","r",stdin);
    freopen("seq.out","w",stdout);
    scanf("%d %d",&n,&p);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    init(1,n,1);
    scanf("%d",&opt);
    for (int i=1;i<=opt;i++)
    {
        scanf("%d",&ch);
        if (ch==1)
        {
           scanf("%d %d %d",&ll,&rr,&v);
           mul(ll,rr,1,v);
        }
        else if (ch==2)
             {
                scanf("%d %d %d",&ll,&rr,&v);
                add(ll,rr,1,v);
             }
             else
             {
                scanf("%d %d",&ll,&rr);
                ans=query(ll,rr,1) % p;
                printf("%I64d\n",ans);
             }
    }
//    system("pause");
    return 0;
}
