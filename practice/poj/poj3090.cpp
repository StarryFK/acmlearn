#include <iostream>
#include <cstdio>
using namespace std;
#define LL long long 
#define RLL(x) scanf("%lld", &x)

LL minp[1005], prime[1005], pcnt=0;
LL phi[1005];

void init(){
	for(LL i=2; i<=1000; i++){
		if(minp[i]==0){
			minp[i]=i;
			prime[pcnt++]=i;
			phi[i]=i-1;
		}
		for(LL j=0; j<pcnt; j++){
			LL p = prime[j];
			if(p > minp[i] || p*i>1000){
				break;
			}
			minp[p*i]=p;
			phi[p*i] = phi[i] * (i%p ? p-1 : p);
		}
	}
}

int main(){
	init();

	//for(int i=0; i<=100; i++){
	//	cout << i << ' ' << phi[i] << endl;
	//}

	LL c;
	RLL(c);
	for(LL i=1; i<=c; i++){
		LL n;
		RLL(n);
		LL ans=0;
		for(LL j=1; j<=n; j++){
			ans += phi[j];
		}
		printf("%lld %lld %lld\n", i, n, 3+2*ans);
	}
}
