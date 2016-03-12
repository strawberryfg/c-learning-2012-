#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MX 66666
using namespace std;

struct node{
	int f[4];
	node(){}
	bool bottom(){
		return f[0] == 0;
	}
	void construct(int a, int b, int c, int d){
		f[0] = a;
		f[1] = b;
		f[2] = c;
		f[3] = d;
	}
    friend node operator + (const node a, const node &b){
		node c;
		for (int i = 0; i < 4; i++)
			c.f[i] = a.f[ b.f[i] ];
		return c;
	}
		
};

char s[MX];
int n, m;
int cmq[MX];
node L, R, B;
int p, l, r, x;
char ch;

node operate(char ch){
	if (ch == 'L')
		return L;
	if (ch == 'R')
		return R;
	return B;
}

void solve(int l, int r){
	printf("%d\n", cmq[r] - cmq[l - 1]);
}

int main(){
	freopen("tetrahedron.in", "r", stdin);
	freopen("tetrahedron.out", "w", stdout);

	L.construct(1, 3, 2, 0);
	R.construct(2, 1, 3, 0);
	B.construct(3, 2, 1, 0);

	scanf("%d\n", &n);
	for (int i = 2; i <= n + 1; i++)
		s[i] = getchar();
	cmq[0] = 0;
	cmq[1] = 1;
	node now;
	now.construct(0, 1, 2, 3);
	for (int j = 2; j <= n + 1; j++){
		now = now + operate(s[j]);
		cmq[j] = cmq[j - 1] + now.bottom();
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++){
		scanf("%d", &p);
		if (p){
			scanf("%d%d", &l, &r);
			solve(l, r);
		}
		else{
			scanf("%d %c", &x, &ch);
			s[x + 1] = ch;
			cmq[0] = 0;
			cmq[1] = 1;
			now.construct(0, 1, 2, 3);
			for (int j = 2; j <= n + 1; j++){
				now = now + operate(s[j]);
				cmq[j] = cmq[j - 1] + now.bottom();
			}
		}
	}
	return 0;
}
