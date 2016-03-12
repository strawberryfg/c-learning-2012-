#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
const int dx[5]={0,-1,0,0,1},dy[5]={0,0,-1,1,0},maxn=110,maxm=110;
int n,m,i,j,tot,sum,g[maxn+1][maxn+1],hash[maxn+1][maxn+1];
struct rec
{
       int x,y,value;
}heap[maxn*maxm+1];      
void up(int num)
{
     int now=num;
     while (now/2>=1 && heap[now/2].value>heap[now].value)
     {
           swap(heap[now/2],heap[now]);     
           now/=2;
     }
}
void insert(int i,int j)
{
     hash[i][j]=1;
     heap[++tot].x=i; heap[tot].y=j; heap[tot].value=g[i][j];
     up(tot);
}
void pre()
{
     for (int i=1;i<=n;i++)
     {
         insert(i,1);
         insert(i,m);
     }
     for (int i=1;i<=m;i++)
     {
         insert(1,i);
         insert(n,i);
     }
}
void down(int num)
{
     int now=num,t1,t2,pnum;
     while (now*2<=tot)
     {
           t1=heap[now*2].value; if (now*2+1<=tot) t2=heap[now*2+1].value; else t2=2147483647;
           if (t1<t2) pnum=0; else pnum=1;
           if (heap[now].value>heap[now*2+pnum].value)
           {
              swap(heap[now],heap[now*2+pnum]);
              now=now*2+pnum;
           }
           else break;
     }
}
void remove(int num)
{
     heap[num]=heap[tot]; heap[tot].x=0; heap[tot].y=0; heap[tot--].value=0;
     down(num);
}
void floodfill(int nx,int ny,int key)
{
     int tx,ty;
     for (int i=1;i<=4;i++)
     {
         tx=nx+dx[i]; ty=ny+dy[i];
         if (tx<=0 || tx>n || ty<=0 || ty>m) continue;
         if (hash[tx][ty]==1) continue;
         if (g[tx][ty]<=key)
         {
            sum+=key-g[tx][ty];
            hash[tx][ty]=1;
            floodfill(tx,ty,key);
         }
         else
         {
            hash[tx][ty]=1;
            heap[++tot].x=tx; heap[tot].y=ty; heap[tot].value=g[tx][ty];
            up(tot);
         }
     }
}
int main()
{
    freopen("water.in","r",stdin);
    freopen("water.out","w",stdout);
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
            scanf("%d",&g[i][j]);
    }
    pre();
    sum=0;
    while (tot>0)
    {
       floodfill(heap[1].x,heap[1].y,heap[1].value);
       remove(1);   
    }
    printf("%d\n",sum);
    return 0;
}
