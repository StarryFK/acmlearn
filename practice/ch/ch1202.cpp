#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#define ll long long
#define RLL(x) scanf("%lld", &x)
#define RI(x) scanf("%d", &x)
using namespace std;

priority_queue<ll> qu;

int main(){
	ll n,m,q,u,v,t;
	RLL(n);
	RLL(m);
	RLL(q);
	RLL(u);
	RLL(v);
	RLL(t);
	double p = (double)u/v;
	ll delta=0;
	ll tmp;
	for(int i=0; i<n; i++){
		RLL(tmp);
		qu.push(tmp);
	}
	ll x, x1, x2;
	for(int i=1; i<=m; i++){
		x = qu.top();
		if(i%t==0){
			printf("%lld ", x+delta);
		}
		qu.pop();
		x += delta;
		x1 = (ll)floor(p*x) - q - delta;
		x2 = x - (ll)floor(p*x) - q - delta;
		qu.push(x1);
		qu.push(x2);
		delta += q;
	}
	puts("");
	int k=0;
	while(!qu.empty()){
		if(++k%t==0){
			printf("%lld ", qu.top()+delta);
		}
		qu.pop();
	}
	puts("");
}
