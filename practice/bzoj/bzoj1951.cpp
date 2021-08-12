#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long LL;
const LL P = 999911659;
const LL m[] = {2,3,4679,35617};

LL jc[4][35618], jci[4][35618];

inline LL pow(LL a, LL n, LL mod){
	LL ans = 1;
	a %= mod;
	for(; n; n>>=1){
		if(n&1){
			ans = ans * a % mod;
		}
		a = a * a % mod;
	}
	return ans;
}
inline void initjc(){
	for(LL j=0; j<4; j++){
		jc[j][0] = jci[j][0] = 1;
		LL mul = 1;
		for(LL i=1; i<=35617; i++){
			mul = mul * i % m[j];
			jc[j][i] = mul;
			jci[j][i] = pow(mul, m[j]-2, m[j]);
		}
	}
}
inline LL com(LL n, LL k, LL modi){
	LL mod = m[modi];
	if(k>n){
		return 0;
	}
	return jc[modi][n] * jci[modi][k] % mod * jci[modi][n-k] % mod;
}
LL lucas(LL n, LL k, LL modi){
	LL mod = m[modi];
	if(n==0){
		return 1;
	}
	return com(n%mod, k%mod, modi) * lucas(n/mod, k/mod, modi) % mod;
}
LL exgcd(LL a, LL b, LL &x, LL &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}else{
		LL d = exgcd(b, a%b, x, y);
		LL z = x;
		x = y;
		y = z - y*(a/b);
		return d;
	}
}
inline LL sub(LL a, LL b, LL mod){
	return (a%mod - b%mod + mod)%mod;
}
LL solve(LL a, LL b){
	LL x,y;
	exgcd(a,b,x,y);
	return sub(x,0,b);
}
LL zgs(LL a[]){
	LL M[4];
	LL ans = 0;
	for(LL i=0; i<4; i++){
		M[i] = (P-1)/m[i];
		ans += a[i] * M[i] % (P-1) * solve(M[i], m[i]) % (P-1);
		ans %= (P-1);
	}
	return ans;
}

int main(){
	LL n,g;
	cin >> n >> g;
	if(g%P==0){
		cout << 0 << endl;
		return 0;
	}
	initjc();
	LL a[]={0,0,0,0};
	for(LL i=0; i<4; i++){
		for(LL j=1; j<=sqrt(n); j++){
			if(n%j==0){
				a[i] += lucas(n,j,i);
				//cout << n << ' ' << j << ' ' << m[i] << ' ' <<lucas(n,j,i) << endl;
				a[i] %= m[i];
				if(n/j != j){
					a[i] += lucas(n,n/j,i);
					a[i] %= m[i];
				}
			}
		}
		//cout << a[i] << endl;
	}
	LL ans = zgs(a);
	//cout << g << ' ' << ans << ' ' << P << endl;
	ans = pow(g,ans,P);
	cout << ans;
}
