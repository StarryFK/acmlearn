#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define LL long long
#define RLL(x) scanf("%lld", &x)

const int E5 = 1e5+5;

LL arr[E5];

int main(){
	LL t;
	RLL(t);
	while(t--){
		LL n,k;
		RLL(n);
		RLL(k);
		for(int i=0; i<n; i++){
			RLL(arr[i]);
		}
		sort(arr, arr+n);
		LL a=0, b=1;
		LL ans=0;
		for(; a<n; a++){
			while(arr[b]-arr[a]<=k && b<n){
				b++;
			}
			ans += b-a-1;

			//cout << a << ' ' << b << endl;

		}
		printf("%lld\n", ans);
	}
}
