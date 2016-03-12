#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream> 
#include<iomanip>
using namespace std;
int main() 
{ 
  long double a,b,c; 
  a=5; 
  b=3; 
  c=a/b; 
  cout<<setiosflags(ios::fixed);
  for (int i=1;i<=10;i++)
  cout<<setprecision(i)<<c<<endl; 
  printf("%.2f\n",5432.458);
  system("pause");  
  return 0;
}
