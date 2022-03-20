#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define LL long long
#define int LL
#define RLL(x) scanf("%lld", &x)
const LL INF = 0x3f3f3f3f3f3f3f3f;
const LL MAX = 2E5+5;

LL mapp[MAX];
LL mapc=0;
LL arr[MAX];
LL ta[MAX];
LL ruc[MAX];
LL luc[MAX];
LL rlc[MAX];
LL llc[MAX];

inline void dec(){
	sort(mapp, mapp+mapc);
	mapc = unique(mapp, mapp+mapc)-mapp;
}
inline LL ind(LL x){	
	return lower_bound(mapp, mapp+mapc, x)-mapp+1;
}                                               
inline LL lb(LL x){                             
	return x&-x;
}
inline LL ps(LL x){
	LL sum=0;
	for(; x; x-=lb(x)){
		sum += ta[x];
	}
	return sum;
}
inline void add(LL x, LL y){
	for(; x<=mapc; x+=lb(x)){
		ta[x] += y;
	}
}

signed main(){
	LL n;
	RLL(n);
	for(LL i=0; i<n; i++){
		RLL(arr[i]);
		mapp[mapc++] = arr[i];
	}
	dec();
	for(LL i=0; i<n; i++){
		arr[i] = ind(arr[i]);
	}
	memset(ta, 0, sizeof(ta));
	for(LL i=0; i<n; i++){
		luc[i] = ps(mapc)-ps(arr[i]);
		llc[i] = ps(arr[i]-1);
		add(arr[i], 1);
	}
	memset(ta, 0, sizeof(ta));
	for(LL i=n-1; i>=0; i--){
		ruc[i] = ps(mapc)-ps(arr[i]);
		rlc[i] = ps(arr[i]-1);
		add(arr[i], 1);
	}
	LL ansv=0, ans6=0;
	for(int i=0; i<n; i++){
		ansv += luc[i] * ruc[i];
		ans6 += llc[i] * rlc[i];
	}
	printf("%lld %lld\n", ansv, ans6);
}

