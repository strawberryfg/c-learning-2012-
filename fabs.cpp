#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    double a;
    scanf("%lf",&a);
    printf("%f\n",fabs(a));
    int b;
    scanf("%d",&b);
    printf("%d\n",abs(b));
    system("pause");
    return 0;
}

//fabs 返回值为float
  abs 返回值为double