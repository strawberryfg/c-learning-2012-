#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
    char s1[100]="fsdafs";
    char s2[100]="grewrf423dsafhkdjsahfk";
    cout<<s1<<" "<<s2<<"\n";
//    strcpy(s1,s2);
    cout<<s1<<" "<<s2<<"\n";
    int a=strcmp(s1,s2);
    if (a<0) cout<<"<"<<"\n"; else cout<<">"<<"\n";
    char x[100]="fdskueozmqljtw";
    char y[100]="zmqljtwhyypca";
    a=strcspn(x,y);
    cout<<a<<"\n";
    char z[100]="fsdafrfddffrsdzwwwgghhwwsqqz";
    char w[100]="fsdafr";
    a=strspn(z,w);
    cout<<a<<"\n";
    strrev(w);
    cout<<w<<"\n";
    char p[]="sAaBCWsfzSQPsdfWEgWhYEHdfE";
    char *q=strupr(p);
    printf("%s\n",q);
//    cout<<q<<"\n";
    char *r=strlwr(p);    
    cout<<r<<"\n"; 
    char *str1="Borland International",*str2="nation",*ptr;
    ptr=strstr(str1,str2);
    printf("The substring is: %s\n",ptr);
    ptr=strchr(str1,'a');
    printf("%s\n",ptr);
    system("pause");
    return 0;
}
