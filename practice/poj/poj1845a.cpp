#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define LL long long
const LL mod = 9901;

inline LL mul(LL a, LL b){
	return (a%mod) * (b%mod) % mod;
}
inline LL qpow(LL a, LL n){
	LL ans=1%mod;
	for(; n; n>>=1){
		if(n&1){
			ans = mul(ans, a);
		}
		a = mul(a, a);
	}
	return ans;
}
inline LL inv(LL b){
	return qpow(b, mod-2);
}
inline LL sub(LL a, LL b){
	return ((a%mod)+mod)-(b%mod);
}
vector<LL> prime;
vector<LL> cnt;

int main(){
	LL a,b;
	cin >> a >> b;
	LL ans = 1;
	for(LL i=2; i<=sqrt(a); i++){
		if(a%i){
			continue;
		}
		LL c=0;
		for(; a%i==0; a/=i){
			c++;
		}
		prime.push_back(i);
		cnt.push_back(c);
	}
	if(a>1){
		prime.push_back(a);
		cnt.push_back(1);
	}
	for(int j=0; j<prime.size(); j++){
		LL c = cnt[j];
		LL i = prime[j];
		if((i-1)%mod){
			ans = mul(ans, mul(sub(qpow(i, b*c+1), 1), inv(i-1)));
		}else{
			ans = mul(ans, b*c+1);
		}
	}
	cout << ans << endl;
}
