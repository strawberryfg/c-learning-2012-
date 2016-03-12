#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
struct student
{
       int a,b;
       student(int a,int b):a(a),b(b){}
       bool operator < (const student &c) const 
       {
            return (a<c.a || (a==c.a && b<c.b));
       }
};
int main()
{
    multiset<student> stu;
    stu.insert(student(15,29));
    stu.insert(student(4,17));
    stu.insert(student(19,12));
    stu.insert(student(8,10));
    stu.insert(student(12,34));
    stu.insert(student(6,1));
    stu.insert(student(17,98));
    stu.insert(student(12,76));
    stu.insert(student(12,16));
    stu.insert(student(8,5));
    stu.insert(student(8,7));
    stu.insert(student(6,48));
    stu.insert(student(6,11));
    stu.insert(student(6,2));
    stu.insert(student(8,22));
    stu.insert(student(19,17));
    stu.insert(student(15,16));
    stu.insert(student(19,21));
    stu.insert(student(4,40));
    stu.insert(student(15,25));
    multiset<student>::iterator iter=stu.begin();
    for (;iter!=stu.end();iter++) printf("%d %d\n",iter->a ,iter->b );
    iter=stu.find(student(8,10));
    printf("%d %d\n",iter->a ,iter->b );
    stu.erase(iter);
    stu.erase(student(12,34));
    system("pause");    
    return 0;
}
