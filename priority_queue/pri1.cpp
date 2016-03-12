#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
priority_queue<pair<int,int>,vector<pair<int,int> >,less<pair<int,int> > > q;
int n,a,b;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d %d",&a,&b);
        q.push(make_pair(a,b));
    }
    for (int i=1;i<=n;i++)
    {
        pair<int,int> c=q.top();
        printf("%d %d\n",c.first ,c.second );
        q.pop();
    }
    system("pause");
    return 0;
}
