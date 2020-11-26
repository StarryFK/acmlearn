#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#define INF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define RLL(x) scanf("%lld", &x)
using namespace std;

queue<ll> que[3];
vector<ll> vec;

int main(){
	ll n,m,q,u,v,t;
	RLL(n);
	RLL(m);
	RLL(q);
	RLL(u);
	RLL(v);
	RLL(t);
	ll tmp;
	for(int i=0; i<n; i++){
		RLL(tmp);
		vec.push_back(tmp);
	}
	sort(vec.begin(), vec.end());
	for(int i=vec.size()-1; i>=0; i--){
		que[0].push(vec[i]);
	}
	ll delta=0;
	ll maxn, maxq=0;
	ll x,px;

	for(int i=1; i<=m; i++){
		maxn = -INF;
		for(int j=0; j<3; j++){
			if(!que[j].empty()){
				if(que[j].front() >= maxn){
					maxn = que[j].front();
					maxq = j;
				}
			}
		}
		x = que[maxq].front();
		x += delta;
		if(i%t==0){
			printf("%lld ", x);
		}
		que[maxq].pop();
		px = x*u/v;

		//cout << px << ' ' << x-px << endl;

		que[1].push(px-delta-q);
		que[2].push(x-px-delta-q);
		delta += q;
	}
	puts("");
	ll kase=1;
	while(!(que[0].empty() && que[1].empty() && que[2].empty())){
		maxn = -INF;
		for(int i=0; i<3; i++){
			if(!que[i].empty()){
				if(que[i].front() >= maxn){
					maxn = que[i].front();
					maxq = i;
				}
			}
		}
		x = que[maxq].front();
		x += delta;
		if(kase%t==0){
			printf("%lld ", x);
		}
		que[maxq].pop();
		kase++;
	}
	puts("");

}
