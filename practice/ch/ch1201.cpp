#include <iostream>
#include <algorithm>
#include <cstdio>
#include <deque>
#include <cstring>
#define ll long long
#define LLINF 0x3f3f3f3f3f3f3f3f
#define RLL(x) scanf("%lld", &x)
using namespace std;


deque<ll> dq;
ll sum[300005];

int main(){
	ll n,m;
	while(~RLL(n)){
		RLL(m);
		memset(sum, 0, sizeof(sum));
		dq.clear();
		dq.push_back(0);
		ll tmp;
		for(int i=1; i<=n; i++){
			RLL(tmp);
			sum[i] = tmp + sum[i-1];
		}

		//cout << "OK" << endl;

		ll maxsd = -LLINF;
		for(int i=1; i<=n; i++){

			//cout << i << endl;

			while(i-dq.front() > m){
				dq.pop_front();
			}
			maxsd = max(maxsd, sum[i] - sum[dq.front()]);

			//cout << "maxsd" << maxsd << endl;

			while(!dq.empty() && sum[dq.back()] > sum[i] ){

				//cout << "pop" << dq.back() << endl;

				dq.pop_back();
			}

			//cout << "OK" << endl;

			dq.push_back(i);

			//cout << "OK" << endl;

		}
		printf("%lld\n", maxsd);
	}
}

