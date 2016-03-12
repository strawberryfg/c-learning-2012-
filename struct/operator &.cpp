#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
struct spe
{
   int s[3];
   int &operator [](int x) { return s[x]; }
}t[2];
int main()
{
    t[0][0]=43; t[0][1]=3455; t[0][2]=43245;
    t[1][0]=432; t[1][1]=98; t[1][2]=777;
    cout<<t[0].s[0]<<" "<<t[0].s[1]<<" "<<t[0].s[2]<<endl;
    cout<<t[1].s[0]<<" "<<t[1].s[1]<<" "<<t[1].s[2]<<endl;
    system("pause");
    return 0;
}
