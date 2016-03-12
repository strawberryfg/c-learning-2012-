#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const char spe[10][6]={"i","pa","te","ni","niti","a","ali","nego","no","ili"};
int cnt,t;
char ts[257],ss[257],*s1;
bool pd;
int main()
{
    freopen("abbr.in","r",stdin);
    freopen("abbr.out","w",stdout);
    scanf("%[^\n]",ts);
    s1=ts;
    t=strcspn(s1," ");
    cnt=0;
    while (t!=strlen(s1))
    {
          strncpy(ss,s1,t);
          strcpy(s1,s1+t+1);
          pd=true;
          for (int i=0;i<10;i++) if (t==strlen(spe[i]) && strncmp(ss,spe[i],t)==0) { pd=false; break; }
          cnt++;
          if (pd || cnt==1) printf("%c",(char)(ss[0]-'a'+'A'));
          t=strcspn(s1," ");
    }
    pd=true;
    for (int i=0;i<10;i++)
        if (strcmp(s1,spe[i])==0) { pd=false; break; }
    cnt++;
    if (pd) printf("%c",(char)(s1[0]-'a'+'A'));
    return 0;
}
