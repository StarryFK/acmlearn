#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define RLL(x) scanf("%lld", &x)
#define LL long long

LL arr[200010];

inline void pt(int x, int y, int ig){
	for(int i=x; i<y; i++){
		if(i==ig){
			continue;
		}
		printf("%lld ", arr[i]);
	}
	puts("");
}

int main(){
	LL t;
	RLL(t);
	while(t--){
		LL n;
		RLL(n);
		for(LL i=0; i<n+2; i++){
			RLL(arr[i]);
		}
		sort(arr, arr+n+2);
		LL sum=0;
		for(LL i=0; i<n; i++){
			sum += arr[i];
		}
		if(sum==arr[n] || sum==arr[n+1]){
			pt(0,n,n+2);
			continue;
		}
		int last = arr[n];
		for(int i=0; i<n; i++){
			sum += last;
			sum -= arr[i];
			last = arr[i];
			if(sum==arr[n+1]){
				pt(0, n+1, i);
				goto nx;
			}
		}
		puts("-1");
nx:;
	}
}
