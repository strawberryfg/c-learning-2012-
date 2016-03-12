#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
FILE *fin=fopen("test.in","r"),*fout=fopen("test.out","w");
int a,b;
int gi()
{
    char ch;
    while (ch=fgetc(fin), ch<'0' || ch>'9');
    int ret=ch-'0';
    while (ch=fgetc(fin), ch>='0' && ch<='9') ret=ret*10+ch-'0';
    return ret;
}
int main()
{
    a=gi(); b=gi();
    fprintf(fout,"%d %d\n",a,b);
    return 0;
}

/*inline void gi(int &x) {
	char ch; while (ch = getchar(), ch<'0' || ch>'9');
	x = ch - '0'; while (ch = getchar(), ch>='0' && ch<='9') x = x * 10 + ch - '0';
}*/