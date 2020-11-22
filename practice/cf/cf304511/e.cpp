#include <iostream>
#define MOD 998244353
#include <cstdio>
#define ll long long 
using namespace std;

ll ans[70];

int main(){
	for(int i=1; i<=65; i++){
		ll sum = 0;
		for(int j=1; j<=i; j++){
			ll mul = 1;
			for(int k=0; k<j; k++){
				mul = (mul*(62-k))%MOD;
			}
			sum = (sum+mul)%MOD;
		}
		ans[i] = sum;
	}
	int n;
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		if(n<=65){
			printf("%lld", ans[n]);
		}else{
			printf("%lld", ans[65]);
		}
		puts("");
	}
}
