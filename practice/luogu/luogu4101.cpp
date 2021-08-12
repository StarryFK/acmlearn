#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

typedef long long LL;
#define RLL(x) scanf("%lld", &x)

int main(){
	LL t;
	RLL(t);
	while(t--){
		LL n,m;
		RLL(n);
		RLL(m);
		LL ans = n/m*(m-1) + max(n%m-1, (LL)0);
		if(ans & 1){
			puts("0");
		}else{
			puts("1");
		}
	}

}
