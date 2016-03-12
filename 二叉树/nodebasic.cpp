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
       NODE(){}
       NODE (int value) : data(value),left(NULL),right(NULL){}       
}a(1),b(2),c(3),d(4),e(5),tmp;
int main()
{
    NODE f=NODE(6);
    NODE *h=&f;
    NODE g(7);
    a.left=&b;
    h->left=&c;    
    system("pause");
    return 0;
}
