#include <cmath>
#include <cstring>
#include <iostream>
#define ull unsigned long long
using namespace std;

const int mod = 9901;

ull pf[100];
ull pcnt[100];
int cnt=0;

bool getpf(ull n) {
	memset(pf, 0, sizeof(pf));
	memset(pcnt, 0, sizeof(pcnt));
	bool prime = true;
	for (int i = 2; i <= sqrt(n); i++) {
		if(n % i == 0) {
			prime = false;
			pf[cnt] = i;
			while(n%i==0){
				n/=i;
				pcnt[cnt]++;
			}
			cnt++;
		}
	}
	if(n>1){
		pf[cnt] = n;
		pcnt[cnt] = 1;
		cnt++;
	}
	return prime;
}

ull powmod(ull a, ull b) {
	ull result=1;
	while(b>0){
		if(b&1){
			result = (result * a)%mod;
		}
		a = (a*a)%mod;
		b >>= 1;
	}
	return result;
}

ull summod(ull p, ull c) {

	//cout << p << ' ' << c << '\n';

	if(c==1){
		return p+1;
	}
	if(c==0){
		return 1;
	}
	if (c & 1) {
		return (summod(p,c/2) * (1+powmod(p,c/2+1)))%mod;
	} else {
		return (powmod(p,c/2)+summod(p,c/2-1)*(1+powmod(p,c/2+1)))%mod;
	}
}

int main() {
	ull a, b;
	cin >> a >> b;
	
	//cout << powmod(a,b) << endl;

	getpf(a);
	ull result = 1;
	for (int i = 0; i < cnt; i++) {

		//cout << pf[i]  << ' ' << pcnt[i]<< endl;

		result = (result * summod(pf[i], b * pcnt[i]))%mod;

		//cout << result << endl;
	}
	cout << result << '\n';
}
