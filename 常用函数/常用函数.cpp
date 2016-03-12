#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    double x=atan(-211232444399343.0);    
    printf("%f\n",x);
    double y=atan2(4,3); //atan2(y,x);
    printf("%f\n",tan(y));        
    system("pause");
    return 0;
}
//asin() [-PI/2,PI/2]
//acos() [0,PI]
//atan() [-PI/2,PI/2]
//atan2(,) [-PI/2,PI/2]
//sinh() cosh() tanh()
//pow(,) x^y
//exp(b*log(a)) a^b
//sqrt() log() log10() 
//ceil() 最小的大于x的整数
//floor() 最大的小于等于x的整数 
//fabs() float abs() double
