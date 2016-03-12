#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#define LL long long
#define maxn 7000020
using namespace std;
int n,cnt,tot;
LL a1,b1,a2,b2,c,d1,d2,tmp,num,last;
priority_queue<LL,vector<LL>,greater<LL> > heap;
int main()
{
    freopen("baying.in","r",stdin);
    freopen("baying.out","w",stdout);
    scanf("%I64d %d",&c,&n);
    scanf("%I64d %I64d %I64d",&a1,&b1,&d1);
    scanf("%I64d %I64d %I64d",&a2,&b2,&d2);
    tot=1; cnt=0; last=0;
    heap.push(c);
    while (cnt<n)
    {
       num=heap.top();
       heap.pop();
       if (num!=last)
       {
          cnt++;
          if (cnt==n) break;
          tmp=a1*num/d1+b1;
          heap.push(tmp);
          tmp=a2*num/d2+b2;
          heap.push(tmp);
          last=num;
       }
    }
    printf("%I64d\n",num);
//    system("pause");
    return 0;
}
