#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<deque>
#define maxn 1000200
using namespace std;
int n,k,a[maxn],minn[maxn],maxx[maxn];
int main()
{
//    freopen("sliding.in","r",stdin);
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    deque<int> q1;    
    for (int i=1;i<=n;i++)
    {
        while (q1.size() && q1.front()<=i-k) q1.pop_front();
        while (q1.size() && a[q1.back()]>=a[i]) q1.pop_back();         
        q1.push_back(i);
        if (i>=k) minn[i]=a[q1.front()];        
    }
    for (int i=k;i<=n-1;i++) printf("%d ",minn[i]);
    printf("%d\n",minn[n]);
    deque<int> q2;
    for (int i=1;i<=n;i++)
    {
        while (q2.size() && q2.front()<=i-k) q2.pop_front();
        while (q2.size() && a[q2.back()]<=a[i]) q2.pop_back(); 
        q2.push_back(i);
        if (i>=k) maxx[i]=a[q2.front()];        
    }
    for (int i=k;i<=n-1;i++) printf("%d ",maxx[i]);
    printf("%d\n",maxx[n]);    
//    system("pause");
    return 0;
}
