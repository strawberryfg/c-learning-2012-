#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct T
{
   int x,y,z;
   friend bool operator < (const T &t1,const T &t2) 
   {
        return (t1.x>t2.x || (t1.x==t2.x && t1.y>t2.y) || (t1.x==t2.x && t1.y==t2.y && t1.z>t2.z) );
   }
   T(int a,int b,int c):x(a),y(b),z(c){}
   T(){}
}ex;
priority_queue<T> q;
int n,a,b,c;
int main()
{
    freopen("pri3.in","r",stdin);
    freopen("pri3.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) 
    {
        scanf("%d %d %d",&a,&b,&c);
        q.push(T(a,b,c));
    }
    for (int i=1;i<=n;i++)
    {
        T now=q.top();
        printf("%d %d %d\n",now.x,now.y,now.z);
        q.pop();
    }
//    system("pause");
    return 0;
}
