#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
#define LL long long
#define RLL(x) scanf("%lld", &x)

const int E5 = 1e5+5;

LL arr[E5];
LL sum[E5];

inline LL log2l(LL num){
	if(num==0){
		return 0;
	}else{
		return log(num)/log(2);
	}
}

inline LL getSum(int i, int j){
	return sum[j] - sum[i-1];
}

int main(){
	LL t;
	RLL(t);
	while(t--){
		LL n;
		RLL(n);
		for(int i=1; i<=n; i++){
			RLL(arr[i]);
			sum[i] = arr[i] + sum[i-1];
		}
		LL ans=0;
		for(LL lo=0; lo<=33; lo++){

			//cout << lo << endl;

			LL ijsum = 0;
			int i=1, j=1;
			while(j<=n){
				----
			}
			ans += (lo+1) * (ijsum);
		}
		printf("%lld\n", ans);
	}

}
