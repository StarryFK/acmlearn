#include <iostream>
using namespace std;
#define LL long long 
const int mod = 10007;

inline int qpow(int a, int n){
	LL ans=1;
	a %= mod;
	for(; n; n>>=1){
		if(n&1){
			ans = ans*a%mod;
		}
		a = a*a%mod;
	}
	return ans;
}
inline int fac(int n){
	LL ans=1;
	for(int i=1; i<=n ;i++){
		ans = ans*(i%mod)%mod;
	}
	return ans;
}

int main(){
	int a,b,k,n,m;
	cin >> a >> b >> k >> n >> m;
	int ans = qpow(a,n)*qpow(b,m)%mod;
	int p = fac(k);
	int s = fac(n)*fac(k-n)%mod;
	int rs = qpow(s, mod-2);
	int c = p * rs % mod;
	ans = ans * c % mod;
	cout << ans << endl;

}
