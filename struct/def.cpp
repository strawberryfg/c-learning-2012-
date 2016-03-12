#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
struct node
{
   int a; 
   double b;
   char *c;
   bool d;
   node(){a=0; b=0.0; c="\0"; d=false; }
   node(int a,double b,char *c,bool d):a(a),b(b),c(c),d(d){}
   //or node(int e,double f,char *g,bool h){a=e; b=f; c=g; d=h;}
   //or node(int e,double f,char *g,bool h):a(e),b(f),c(g),d(h){}
}x[4];
int main()
{
    x[0]=node(); 
    x[1]=node(12,423.3432,"sfsdfdsrew",true);
    x[2]=node(432,-13.532,"fdseq",false);
    cout<<x[2].c<<x[2].d<<x[1].b;
    system("pause");
    return 0;
}
