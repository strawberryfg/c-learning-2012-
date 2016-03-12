#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<ctime>
#define maxrand 100000000
#define maxn 100000 
using namespace std;
struct treap
{
   treap *ch[2];
   int key,num,a;
}spe;
treap *nil,*root,*fmin,*fmax;
int t,k,p;
treap *leftrotate(treap *x)
{
      treap *y;
      y=x->ch[1];
      x->ch[1]=y->ch[0];
      y->ch[0]=x;
      return y;
}
treap *rightrotate(treap *x)
{
      treap *y;
      y=x->ch[0];
      x->ch[0]=y->ch[1];
      y->ch[1]=x;
      return y;
}
treap *insert(treap *root,int n,int v)
{
    if (root==nil)
    {
        treap *tmp=new struct treap;
        tmp->ch[0]=tmp->ch[1]=nil;
        tmp->key=v; tmp->num=rand()%maxrand+1;
        tmp->a=n;
        return tmp;         
    }  
    else
    {
        if (v<root->key)
        {
           root->ch[0]=insert(root->ch[0],n,v);
           if (root->ch[0]->num > root->num) root=rightrotate(root);
        }
        else
        {
           root->ch[1]=insert(root->ch[1],n,v);
           if (root->ch[1]->num > root->num) root=leftrotate(root); 
        }
        return root;
    }
}
treap *dfs(treap *x)
{
    if (x->ch[1]==nil) return x;
       else return dfs(x->ch[1]);
}
treap *dfs2(treap *x)
{
    if (x->ch[0]==nil) return x;
       else return dfs2(x->ch[0]);  
}
treap *del(treap *now,int v)
{
    if (now==nil) return now;  
    if (v<now->key) now->ch[0]=del(now->ch[0],v);
       else if (v>now->key) now->ch[1]=del(now->ch[1],v);
               else {
                       if (now->ch[0]==nil && now->ch[1]==nil) return nil;
                       if (now->ch[0]->num > now->ch[1]->num)
                       {
                           now=rightrotate(now);
                           now->ch[1]=del(now->ch[1],v);
                       }
                       else
                       {
                           now=leftrotate(now);
                           now->ch[0]=del(now->ch[0],v);
                       }
                    }  
    return now;                    
}
int main()
{
//    freopen("dq.in","r",stdin);
//    freopen("dq.out","w",stdout);    
    srand(time(0));
    nil=new struct treap;
    nil->key=0; nil->num=0; nil->a=0;
    nil->ch[0]=nil; nil->ch[1]=nil; 
    root=nil;
    for (scanf("%d",&t);t;scanf("%d",&t))
    {                                                       
        if (t==1)
        {
            scanf("%d %d",&k,&p);
            root=insert(root,k,p);
        }
        else if (t==2)
             {
                fmax=dfs(root);
                printf("%d\n",fmax->a);
                root=del(root,fmax->key);                
             }   
             else
             {
                fmin=dfs2(root);
                printf("%d\n",fmin->a);
                root=del(root,fmin->key); 
             }
    }
//    system("pause");
    return 0;
}
