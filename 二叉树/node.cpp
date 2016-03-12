#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
struct NODE
{
       int data;
       NODE *left;
       NODE *right;
       NODE (int value) : data(value),left(NULL),right(NULL){}       
       NODE(){}
}a(1),b(2),c(3),d(4),e(5),f(6),g(7);
void pre_vis(NODE *p)
{     
     printf("%d ",(*p).data);
     if ((*p).left) pre_vis((*p).left);
     if ((*p).right) pre_vis((*p).right);
}
void mid_vis(NODE p)
{
     if (p.left) mid_vis(*p.left);
     printf("%d ",p.data);
     if (p.right) mid_vis(*p.right);     
}
void suc_vis(NODE p)
{
     if (p.left) suc_vis(*p.left);
     if (p.right) suc_vis(*p.right);     
     printf("%d ",p.data);     
}
int main()
{
    a.left=&b;
    a.right=&c;
    b.left=&d;
    b.right=&e;
    e.left=&g;
    c.right=&f;
    pre_vis(&a);
    printf("\n");
    mid_vis(a);
    printf("\n");
    suc_vis(a);
    printf("\n");
    system("pause");
    return 0;
}
