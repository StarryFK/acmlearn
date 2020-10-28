#include <iostream>
#define ll long long
using namespace std;

int mod=100000;

ll powmod(int a, int n){
	ll result=1;
	while(n>0){
		if(n&1){
			result = result * a % mod;
		}
		a = a*a%mod;
		n>>=1;
	}
	return result;
}

int main(){
	int a,b;
	cin >> a >> b;
	cout << powmod(a,b);
}
