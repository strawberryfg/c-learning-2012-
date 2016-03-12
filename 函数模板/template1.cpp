#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    char * b="adsfdsfsdfsd";
    cout<<b<<endl;
    const char * const a=b;
    //const char * p  *p can't be modified         *p=......(wrong)
    //char * const p;
    //const int &a=b; a not written; b=14 can 
    cout<<a<<endl;
    b="fljwerlj";    
    cout<<a<<" "<<b<<endl;
    system("pause");
    return 0;
}
