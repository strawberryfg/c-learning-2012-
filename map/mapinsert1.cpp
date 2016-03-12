#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<map>
using namespace std;
typedef pair<int,int> COUP;
typedef map<int,int>::iterator POS;
typedef pair<POS,bool> RET;
int main()
{
    map<int,int,greater<int> > m;
    m.insert(COUP(2,12));
    m.insert(COUP(1,16));
    m.insert(COUP(4,7));
    RET a=m.insert(COUP(2,10));
    cout<<a.first->second <<" "<<a.second <<"\n";
    a=m.insert(COUP(-1,4));
    m.insert(COUP(3,34));
    m.insert(COUP(12,4332));
    m.insert(COUP(7,4));
    m.insert(COUP(9,92));
    cout<<a.second <<"\n";
    POS iter1=m.begin();
    for (;iter1!=m.end();iter1++) printf("%d %d\n",iter1->first,iter1->second);
    POS iter2=m.begin();     
    iter2++; iter2++;
    POS iter3=iter2;
    iter3++; iter3++; iter3++; iter3++; iter3++;
    map<int,int> m1;
    m1.insert(iter2,iter3);
    POS iter=m1.begin();
    for (;iter!=m1.end();iter++) printf("%d %d\n",iter->first,iter->second);
    map<int,int> m2(iter2,iter3);
    iter=m2.begin();
    for (;iter!=m2.end();iter++) printf("%d %d\n",iter->first,iter->second);
    map<int,int> m3(m1);
    map<int,int> m4=m1;
    POS ite=m.insert(++iter2,COUP(10,5));
    for (int i=1;i<=3;i++) printf("\n");    
    cout<<ite->first << " " <<ite->second<<" \n\n";
    iter1=m.begin();
    for (;iter1!=m.end();iter1++) printf("%d %d\n",iter1->first,iter1->second);
    system("pause");
    return 0;
}
