#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
//#include<algorithm>
#define maxn 80020
#define LL long long
using namespace std;
struct rec
{
   int l,r;
   LL sum;
}tree[4*maxn];
int n,q,x,y;
LL res,d,td;
LL v[maxn],sum[maxn];
char c,ch;
LL max(LL x,LL y)
{
   if (x>y) return x; else return y;
}
void init(int f,int t,int x)
{
     tree[x].l=f; tree[x].r=t;
     if (f==t)
     {
        tree[x].sum=sum[f];
        return;
     }
     init(f,(f+t)/2,x*2);
     init((f+t)/2+1,t,x*2+1);
     tree[x].sum=max(tree[x*2].sum,tree[x*2+1].sum);
     tree[x].sum=max(tree[x].sum,tree[x*2].sum+tree[x*2+1].sum);
}
void work(int f,int t,int x)
{
     int mid;
     if (f<=tree[x].l && tree[x].r<=t)
     {
        tree[x].sum=max(sum[f]-d,0);
        sum[f]-=d;
        return;
     }
     mid=(tree[x].l+tree[x].r)/2;
     if (f<=mid) work(f,t,x*2);
     if (t>mid) work(f,t,x*2+1);
     tree[x].sum=max(tree[x*2].sum,tree[x*2+1].sum);
     tree[x].sum=max(tree[x].sum,tree[x*2].sum+tree[x*2+1].sum);     
}
LL ask(int f,int t,int x)
{
    int mid;
    LL t1,t2,res;
    mid=(tree[x].l+tree[x].r)/2;
    if (f<=tree[x].l && tree[x].r<=t) return max(0,tree[x].sum);
    if (t<=mid)
    {
        if (f<=tree[x].l && tree[x].r<=t) return tree[x].sum;
            else return ask(f,t,x*2);
    }
    if (f>mid)
    {
        if (f<=tree[x].l && tree[x].r<=t) return tree[x].sum;
            else return ask(f,t,x*2+1);
    }
    t1=ask(f,t,x*2);
    t2=ask(f,t,x*2+1);
    res=max(t1,t2);
    res=max(res,t1+t2);
    return res;
}
int main()
{
    freopen("river.in","r",stdin);
    freopen("river.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&v[i]);
        sum[i-1]=v[i]-v[i-1];
    }
    init(1,n-1,1);
    scanf("%d",&q);
    ch=getchar();
    for (int i=1;i<=q;i++)
    {
        ch=getchar(); 
        c=getchar();
        if (ch=='C')
        {
            scanf("%I64d %I64d %I64d",&x,&y,&d);
            td=d;
            if (x-1>0)
            {
               d=-d;
               work(x-1,x-1,1); 
            }
            d=td;
            if (y<n-1)
            {
               work(y,y,1);
            }
        }
        else
        {
            scanf("%d %d",&x,&y);
            if (x==y) printf("0\n");
               else {
                      res=ask(x,y-1,1);
                      printf("%I64d\n",res);
                    }
        }
//        for (int j=1;j<=5;j++) printf("%I64d ",tree[j].sum);
//        printf("\n");
        ch=getchar();
    }
//    system("pause");
    return 0;
}
