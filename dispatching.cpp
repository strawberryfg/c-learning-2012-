#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 200020
#define maxv 2147483647
#define LL long long
using namespace std;
struct gtype
{
   int v,nxt;
}g[maxn];
struct trtype
{
   int left,right,son,ran;
   LL key,sum;
}tr[maxn*20];
int n,fa,root,top,total,tot,edge[maxn],from[maxn],stack[maxn*20];
LL m,ans,a[maxn],value[maxn];
void addedge(int x,int y)
{
     g[++tot].v=y; g[tot].nxt=edge[x]; edge[x]=tot;
}
int getnode()
{
    if (!top) return ++total;
       else return stack[top--];
}
void update(int x)
{
     tr[x].son=tr[tr[x].left].son+tr[tr[x].right].son+1;
     tr[x].sum=tr[tr[x].left].sum+tr[tr[x].right].sum+1;
}
int rightrotate(int x)
{
    int y=tr[x].left;
    tr[x].left=tr[y].right;
    tr[y].right=x;
    update(x);
    update(y);
    return y;    
}
int leftrotate(int x)
{
    int y=tr[x].right;
    tr[x].right=tr[y].left;
    tr[y].left=x;
    update(x);
    update(y);
    return y;
}
int insert(int x,LL v)
{
    int now;
    if (!x)
    {
       now=getnode();
       tr[now].left=tr[now].right=0; tr[now].son=1;
       tr[now].key=tr[now].sum=v; tr[now].ran=rand()%maxv; 
       return now;
    }
    else
    {
        if (v<tr[x].key)
        {
           tr[x].left=insert(tr[x].left,v);
           if (tr[tr[x].left].ran>tr[x].ran) x=rightrotate(x);
        }
        else
        {
           tr[x].right=insert(tr[x].right,v);
           if (tr[tr[x].right].ran>tr[x].ran) x=leftrotate(x);  
        }
        update(x);
        return x;
    }
}
void recycle(int x,int y)
{
     if (!x) return;
     from[y]=insert(from[y],tr[x].key);
     recycle(tr[x].left,y);
     recycle(tr[x].right,y);
     stack[++top]=x;
}
bool check(int x,int posi)
{
     LL ret=0;
     while (x)
     {
        if (tr[tr[x].left].son+1==posi) { ret+=tr[tr[x].left].sum+tr[x].key; break; }
           else if (tr[tr[x].left].son>=posi) x=tr[x].left;
                   else { ret+=tr[tr[x].left].sum+tr[x].key; posi-=tr[tr[x].left].son+1; x=tr[x].right; }
        if (ret>m) break;                      
     }
     return (ret<=m);
}
void work(int x)
{
     int p,num1,num2,le,ri,mid,opt;
     LL res;
     p=edge[x];
     while (p)
     {
        work(g[p].v);
        if (!from[x]) from[x]=from[g[p].v];
           else {
                   if (tr[from[x]].son>tr[from[g[p].v]].son)
                   {
                      num1=from[g[p].v]; num2=x; opt=1;
                   }
                   else
                   {
                      num1=from[x]; num2=g[p].v; opt=2; 
                   }
                   recycle(num1,num2);
                   if (opt==2) from[x]=from[g[p].v];
                }
        p=g[p].nxt;
     }
     from[x]=insert(from[x],a[x]);
     le=1; ri=tr[from[x]].son;
     res=-1;
     while (le<=ri)
     {
        mid=(le+ri)/2;
        if (check(from[x],mid)) { res=mid; le=mid+1; }
           else ri=mid-1; 
     }
     if (res!=-1) res*=value[x];
     if (res>ans) ans=res;
}
int main()
{
    freopen("dispatching.in","r",stdin);
    freopen("dispatching.out","w",stdout);
    srand(time(0));
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        scanf("%d %I64d %I64d",&fa,&a[i],&value[i]);
        if (fa) addedge(fa,i); else root=i;
    }
    ans=0;
    work(root);
    printf("%I64d\n",ans);
//    system("pause");
    return 0;
}
