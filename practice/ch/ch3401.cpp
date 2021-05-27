#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define LL long long
#define RLL(x) scanf("%lld", &x)
#define RS(x) scanf("%s", x)

LL n,m,t,act;
LL l=1;
char op[100];
char ops[15][10];
LL lenops[15];
LL st[100];
LL trans[65][100][100];

inline LL pos(LL i, LL j){
	return (i-1)*m+j;
}
LL gcd(LL a, LL b){
	return b ? gcd(b,a%b) : a;
}
inline LL lcm(LL a, LL b){
	return a/gcd(a,b)*b;
}
inline bool valid(LL i, LL j){
	return i>=1 && i<=n && j>=1 && j<=m;
}
LL tmp[100][100];
inline void mamulma(LL a[100][100], LL b[100][100], LL size){
	memset(tmp, 0, sizeof(tmp));
	for(LL i=0; i<=size; i++){
		for(LL j=0; j<=size; j++){
			for(LL k=0; k<=size; k++){
				tmp[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	memcpy(a, tmp, sizeof(tmp));
}
inline void mamulmar(LL a[100][100], LL b[100][100], LL size){
	memset(tmp, 0, sizeof(tmp));
	for(LL i=0; i<=size; i++){
		for(LL j=0; j<=size; j++){
			for(LL k=0; k<=size; k++){
				tmp[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	memcpy(b, tmp, sizeof(tmp));
}
LL tvec[100];
inline void vecmulma(LL f[100], LL ma[100][100], LL size){
	memset(tvec, 0, sizeof(tvec));
	for(LL j=0; j<=size; j++){
		for(LL k=0; k<=size; k++){
			tvec[j] += f[k] * ma[k][j];
		}
	}
	memcpy(f, tvec, sizeof(tvec));
}
LL ptmp[100][100];
inline void mapow(LL ma[100][100], LL n, LL size){
	memset(ptmp, 0, sizeof(ptmp));
	for(LL i=0; i<=size; i++){
		ptmp[i][i]=1;
	}
	for(; n; n>>=1){
		if(n&1){
			mamulma(ptmp, ma, size);
		}
		mamulma(ma, ma, size);
	}
	memcpy(ma, ptmp, sizeof(ptmp));
}

int main(){
	RLL(n);
	RLL(m);
	RLL(t);
	RLL(act);
	for(LL i=0; i<n; i++){
		RS(op+i*m+1);
	}
	for(LL i=1; i<=n*m; i++){
		op[i] -= '0';
	}
	for(LL i=0; i<act; i++){
		RS(ops[i]);
		lenops[i] = strlen(ops[i]);
		l = lcm(l, lenops[i]);
	}
	memset(trans, 0, sizeof(trans));
	for(LL k=0; k<l; k++){
		trans[k][0][0]=1;
		for(LL i=1; i<=n; i++){
			for(LL j=1; j<=m; j++){
				LL curop = op[pos(i,j)];
				char opch = ops[curop][k%lenops[curop]];
				if(opch=='N'){
					if(valid(i-1,j)){
						trans[k][pos(i,j)][pos(i-1,j)]=1;
					}
				}else if(opch=='S'){
					if(valid(i+1,j)){
						trans[k][pos(i,j)][pos(i+1,j)]=1;
					}
				}else if(opch=='E'){
					if(valid(i,j+1)){
						trans[k][pos(i,j)][pos(i,j+1)]=1;
					}
				}else if(opch=='W'){
					if(valid(i,j-1)){
						trans[k][pos(i,j)][pos(i,j-1)]=1;
					}
				}else if(opch=='D'){
					
				}else{
					opch -= '0';
					trans[k][0][pos(i,j)] = opch;
					trans[k][pos(i,j)][pos(i,j)]=1;
				}
			}
		}
		if(k>0){
			mamulmar(trans[k-1], trans[k], n*m);
		}
	}
	memset(st, 0, sizeof(st));
	st[0]=1;
	if(t/l>0){
		mapow(trans[l-1], t/l, n*m);
		vecmulma(st, trans[l-1], n*m);
	}
	if(t%l>0){
		vecmulma(st, trans[t%l-1], n*m);
	}
	LL ans = 0;
	for(LL i=1; i<=n*m; i++){
		ans = max(ans, st[i]);
	}
	printf("%lld\n", ans);
}
