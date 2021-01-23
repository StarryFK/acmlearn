#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define ULL unsigned long long
#define RULL(x) scanf("%llu", &x)

ULL phi(ULL n){
	ULL ans = n;
	for(ULL i=2; i<=sqrt(n); i++){
		if(n%i==0){
			ans = ans/i*(i-1);
			while(n%i==0){
				n/=i;
			}
		}
	}
	if(n>1){
		ans = ans/n * (n-1);
	}
	return ans;
}

int main(){
	ULL n;
	while(~RULL(n)){
		printf("%llu\n", phi(n)/2); 
	}
}
