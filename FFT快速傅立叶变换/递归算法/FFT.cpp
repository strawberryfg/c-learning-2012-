#include"stdafx.h"
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#define pi 3.1415926535897932384626433832795
int n;
double tmp;
struct complex
{
	double real,virt;
	complex(){ real=virt=0; }
	complex(double s,double t):real(s),virt(t){}
	friend complex operator +(const complex A,const complex &B)
	{
		complex C;
		C.real=A.real+B.real;
		C.virt=A.virt+B.virt;
		return C;
	}
	friend complex operator -(const complex A,const complex &B)
	{
		complex C;
		C.real=A.real-B.real;
		C.virt=A.virt-B.virt;
		return C;
	}
	friend complex operator *(const complex A,const complex &B)
	{
		complex C;
		C.real=A.real*B.real-A.virt*B.virt;
		C.virt=A.real*B.virt+A.virt*B.real;
		return C;
	}
}*a,*b,*c,*U,*V,*C,*D;
void print(complex A) { printf("%lf + %lfi\n",A.real,A.virt); }
complex *DFT(complex *a,complex wn,int n,int opt)
{
	if (n==1) return a;
	complex *y,*a0,*a1,*y0,*y1;
	y=(complex *)malloc(n*sizeof(complex));
	a0=(complex *)malloc(n/2*sizeof(complex));
	a1=(complex *)malloc(n/2*sizeof(complex));
	y0=(complex *)malloc(n/2*sizeof(complex));
	y1=(complex *)malloc(n/2*sizeof(complex));
	complex w(1,0);
	for (int i=0;i<n/2;i++) a0[i]=a[2*i];
    y0=DFT(a0,wn,n/2,opt);
	for (int i=0;i<n/2;i++) a1[i]=a[2*i+1];
	y1=DFT(a1,wn,n/2,opt);
	wn=complex(cos(opt*2*pi/n),sin(opt*2*pi/n));
	for (int k=0;k<n/2;k++)
	{
		y[k]=y0[k]+w*y1[k];
		y[k+n/2]=y0[k]-w*y1[k];
		w=w*wn;
	}
	return y;
}
complex *FFT(int n)
{
	U=(complex *)malloc(n*sizeof(complex));
	V=(complex *)malloc(n*sizeof(complex));
	C=(complex *)malloc(n*sizeof(complex));
	D=(complex *)malloc(n*sizeof(complex));
	U=DFT(a,complex(0,0),n,1);
	V=DFT(b,complex(0,0),n,1);
	for (int i=0;i<n;i++) C[i]=U[i]*V[i];
	D=DFT(C,complex(0,0),n,-1);
	for (int i=0;i<n;i++) D[i]=D[i]*complex(1/(double)n,0);
	return D;
	//coefficient : C[k]  -j,n
}
int main()
{
	freopen("FFT.in","r",stdin);
	freopen("FFT.out","w",stdout);
	//printf("Please enter the degree of Polynomial|n % 2 must be 0:\n");
	scanf("%d",&n);
	int t=1;
	while (t<n) t*=2;
	//printf("Please enter Polynomial A | n coefficient numbers, starting from 0;\n");
	a=(complex *)malloc(2*t*sizeof(complex));
	b=(complex *)malloc(2*t*sizeof(complex));
	c=(complex *)malloc(2*t*sizeof(complex));
	for (int i=0;i<n;i++) { scanf("%lf",&tmp); a[i]=complex(tmp,0); }
	//printf("Please enter Polynomial B | n coefficient numbers, starting from 0;\n");
	for (int i=0;i<n;i++) { scanf("%lf",&tmp); b[i]=complex(tmp,0); }
	for (int i=n;i<2*t;i++) a[i]=b[i]=complex(0,0);
	n=t;
	c=FFT(2*n);
	for (int i=0;i<2*n;i++) print(c[i]);
	//system("pause");
	return 0;
}
