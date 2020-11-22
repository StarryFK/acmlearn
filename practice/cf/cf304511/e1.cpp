#include <iostream>
#define ull unsigned long long 
#include <cstdio>
#define MOD 998244353
#define RULL(x) scanf("%llu", &x)
#define RI(x) scanf("%d", &x)
using namespace std;

ull powmod(ull a, ull n){
	ull ans = 1;
	for(; n; n>>=1){
		if(n&1){
			ans = (ans*a)%MOD;
		}
		a = (a*a)%MOD;
	}
	return ans;
}

int main(){
	int t;
	ull n;
	RI(t);
	while(t--){
		RULL(n);
		ull ans = powmod(62, n);
		printf("%lld\n", ans);
	}
}
