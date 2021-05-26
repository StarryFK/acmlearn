#include <iostream>
#include <cstdio>
using namespace std;
#define LL long long
#define RLL(x) scanf("%lld", &x)
#define RS(x) scanf("%s", x)

LL n,m,t,act;
LL l=1;
char op[100];
char ops[15][10];
int st[100];
int trans[65][100];

inline LL pos(LL i, LL j){
	return (i-1)*m+j;
}
LL gcd(LL a, LL b){
	return b ? gcd(b,a%b) : a;
}
inline LL lcm(LL a, LL b){
	return a/gcd(a,b)*b;
}

int main(){
	RLL(n);
	RLL(m);
	RLL(t);
	RLL(act);
	for(int i=0; i<n; i++){
		RS(op+i*m+1);
	}
	for(int i=1; i<=n*m; i++){
		op[i] -= '0';
	}
	for(int i=1; i<=act; i++){
		RS(ops[i]);
		l = lcm(l, strlen(ops[i]));
	}
	for(int k=0; k<l; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				char curop = ops[k%l]
			}
		}
	}
}
