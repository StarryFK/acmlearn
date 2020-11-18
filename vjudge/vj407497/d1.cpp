#include <iostream>
#define ull unsigned long long
using namespace std;

ull powmod(ull a, ull n){
	ull ans=1;
	for(; n; n>>=1){
		if(n&1){
			ans = ans * a;
		}
		a = a*a;
	}
	return ans;
}

int main(){
	ull a,b;
	while(cin >> a >> b){
		ull x;
		bool ok=false;
		for(x=1; powmod(a, x)<1e18; x++){

			cout << x << endl;

			if(powmod(a,x)==b*x){
				ok=true;
				break;
			}
		}
		
		//cout << "ok" << endl;

		if(ok){
			cout << powmod(a,x) << endl;
		}else{
			cout << 0 << endl;
		}
	}
}
