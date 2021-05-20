#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define LL long long
#define LINF 0x3f3f3f3f3f3f3f3f

LL phi(LL n){
	LL ans = n;
	for(LL i=2; i<=sqrt(n); i++){
		if(n%i==0){
			ans = ans/i*(i-1);
			while(n%i==0){
				n/=i;
			}
		}
	}
	if(n>1){
		ans = ans/n*(n-1);
	}
	return ans;
}
LL gcd(LL a, LL b){
	return b ? gcd(b, a%b) : a;
}
LL mul(LL a, LL b, LL mod){
	LL ans = 0;
	for(; b; b>>=1){
		if(b&1){
			ans = ans+a % mod;
		}
		a = a*2 % mod;
	}
	return ans;
}
LL qpow(LL a, LL n, LL mod){
	LL ans = 1%mod;
	for(; n; n>>=1){
		if(n&1){
			ans = mul(ans, a, mod)%mod;
		}
		a = mul(a,a,mod)%mod;
	}
	return ans;
}

int main(){
	LL l;
	int kase=1;
	while(cin>>l){
		if(l==0){
			break;
		}
		LL d = gcd(l, 8);
		LL mod = 9*l/d;
		LL ans = LINF;
		LL phimod = phi(mod);

		//cout << "mod" << mod << "phimod" << phimod << endl;

		for(LL i=1; i<=sqrt(phimod); i++){

			//cout << i << endl;

			if(phimod%i){
				continue;
			}
			if(qpow(10, i, mod)==1%mod){
				ans = min(ans, i);
			}
			if(qpow(10, phimod/i, mod)==1%mod){
				ans = min(ans, phimod/i);
			}
		}
		cout << "Case " << (kase++) << ": " << (ans==LINF ? 0 : ans) << '\n';
	}
}
