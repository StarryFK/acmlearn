#include <iostream>
#include <algorithm>
#include <cstdio>
#define RLL(x) scanf("%lld", &x)
#define RI(x) scanf("%d", &x)
#define ll long long 
using namespace std;

int main(){
	int n;
	ll sum=0;
	ll tmp;
	ll maxsum=-0x3f3f3f3f3f3f3f3f;
	while(~RI(n)){
		sum=0;
		maxsum=0;
		for(int i=0; i<n; i++){
			RLL(tmp);
			sum += tmp;
			maxsum = max(maxsum, sum);
			//cout << sum << endl;
			//cout << maxsum << endl;
		}
		printf("%lld\n", maxsum+233);
	}
}
