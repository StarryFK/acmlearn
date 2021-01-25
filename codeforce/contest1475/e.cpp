#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
#define RI(x) scanf("%d", &x)
#define LL long long
const int MOD=1e9+7;

int buck[1005];
LL calc[1005][1005];

LL qpow(int a, int n){
	LL ans=1;
	for(; n>0; n>>=1){
		if(n&1){
			ans = ans * a % MOD;
		}
		a = a*a % MOD;
	}
	return ans;
}

int main(){
	int t;
	RI(t);
	for(int i=0; i<1005; i++){
		calc[i][0] = 1;
		calc[i][i] = 1;
	}
	for(int i=1; i<1005; i++){
		for(int j=1; j<i; j++){
			calc[i][j] = calc[i-1][j-1] + calc[i-1][j] % MOD;
		}
	}

	//cout << "yes" << endl;

	while(t--){
		int n,k;
		RI(n);
		RI(k);
		memset(buck, 0, sizeof(buck));
		for(int i=0; i<n; i++){
			int a;
			RI(a);

			//cout << a << endl;

			buck[a]++;
		}
		LL ans=1;
		for(int i=n; i>=0; i--){
			int sl=0;
			if(buck[i] && k){
				sl = min(buck[i], k);
				k -= sl;

				//cout << "k" << k << endl;
				//cout <<' ' << i << ' ' << buck[i] << ' ' << sl << endl;

			}
			ans = ans * calc[buck[i]][sl] % MOD;  
		}
		printf("%lld\n", ans);
	}
	return 0;
}
