#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define RLL(x) scanf("%lld", &x)
#define LL long long 

LL gcd(LL a, LL b){
	return (b ? gcd(b,a%b) : a);
}
inline LL lcm(LL a, LL b){
	return a/gcd(a,b)*b;
}
LL exgcd(LL a, LL b, LL &x, LL &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}else{
		LL d = exgcd(b, a%b, x, y);
		LL z=x; x=y; y=z-(a/b)*y;
		return d;
	}
}
inline LL sub(LL a, LL b, LL mod){
	return (a%mod-b%mod+mod)%mod;
}

int main(){
	LL k;
	while(~RLL(k)){
		LL a, r;
		RLL(a);
		RLL(r);
		LL m = a;
		LL x = r;
		bool ok=true;
		for(LL i=1; i<k; i++){
			RLL(a);
			RLL(r);
			if(sub(r,x,a) % gcd(m,a)){
				ok=false;
			}
			LL x0, y0;
			exgcd(m, a, x0, y0);
			x0 = x0 * sub(r,x,a) / gcd(m,a);
			x0 = sub(x0,0,a/gcd(m,a));
			x = x + x0*m;
			m = lcm(m, a);
			x = sub(x,0,m);
		}
		if(ok==true){
			printf("%lld\n", x);
		}else{
			puts("-1");
		}
	}
}

