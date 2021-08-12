#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define RLL(x) scanf("%lld", &x)
typedef long long LL;
const LL mod = 2017;

LL ma[31][31];
LL st[31];
LL N,M;

inline void mulmama(LL a[31][31], LL b[31][31]){
	LL tmp[31][31];
	for(LL i=0; i<=N; i++){
		for(LL j=0; j<=N; j++){
			tmp[i][j] = 0;
			for(LL k=0; k<=N; k++){
				tmp[i][j] += a[i][k] * b[k][j] % mod;
				tmp[i][j] %= mod;
			}
		}
	}
	memcpy(a, tmp, sizeof(tmp));
}
inline void mulvma(LL v[31], LL a[31][31]){
	LL tv[31];
	for(LL j=0; j<=N; j++){
		tv[j]=0;
		for(LL k=0; k<=N; k++){
			tv[j] += v[k] * a[k][j] % mod;
			tv[j] %= mod;
		}
	}
	memcpy(v, tv, sizeof(tv));
}
inline void powma(LL a[31][31], LL n){
	LL ans[31][31];
	for(LL i=0; i<=N; i++){
		ans[i][i] = 1;
	}
	for(; n>0; n>>=1){
		if(n&1){
			mulmama(ans, a);
		}
		mulmama(a,a);
	}
	memcpy(a, ans, sizeof(ans));
}

int main(){
	RLL(N);
	RLL(M);
	for(LL i=0; i<=N; i++){
		ma[i][i] = 1;
		ma[i][0] = 1;
	}
	for(LL i=0; i<M; i++){
		LL u,v;
		RLL(u);
		RLL(v);
		ma[u][v] = 1;
		ma[v][u] = 1;
	}
	LL t;
	RLL(t);

	//cout << t << endl;
	//for(int i=0; i<=N; i++){
	//	for(int j=0; j<=N; j++){
	//		cout << ma[i][j] << ' ';
	//	}
	//	cout << endl;
	//}

	powma(ma, t);

	//for(int i=0; i<=N; i++){
	//	for(int j=0; j<=N; j++){
	//		cout << ma[i][j] << ' ';
	//	}
	//	cout << endl;
	//}

	st[1]=1;
	mulvma(st, ma);
	LL ans = 0;
	for(int i=0; i<=N; i++){
		ans = (ans+st[i]) % mod;
	}
	printf("%lld\n", ans);
}
