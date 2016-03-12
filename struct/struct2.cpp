#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
struct node1
{
       int a,b;
       bool c;
       node1(){}
       node1(int a,int b,bool c):a(a),b(b),c(c){}
       //or node1(int d,int e,bool f):a(d),b(e),c(f){}
       node1(int a,int b):a(a),b(b){}
       void construct(int d,int e,bool f)
       {
            a=d; b=e; c=f;
       }
       friend node1 operator +(node1 x,node1 y)
       {
          node1 tmp;
          tmp.a=x.a+y.a;
          tmp.b=x.b+y.b;
          tmp.c=x.c | y.c;
          return tmp;
       }
};
node1 p,s,t;
node1 q(12,32,false);
node1 r(98,432);
node1 operator -(node1 x,node1 y)
{
   node1 tmp;
   tmp.a=x.a-y.a;
   tmp.b=x.b-y.b;
   tmp.c=x.c & y.c;
   return tmp;
}
int main()
{
    p.construct(43,989,true);
    s=p+q;
    printf("%d %d ",s.a,s.b);
    cout<<s.c<<"\n";
    t=p-q;
    printf("%d %d ",t.a,t.b);
    cout<<t.c<<"\n";
    system("pause");
    return 0;
}
