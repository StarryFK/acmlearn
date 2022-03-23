#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define LL long long 
#define int LL
#define RLL(x) scanf("%lld", &x)
const LL MAX = 8005;

LL ta[MAX];
LL lg2[MAX];
LL ans[MAX];
LL pre[MAX];
LL n;

inline LL lb(LL x){
	return x&(-x);
}
inline void add(LL pos, LL num){
	for(; pos<=n; pos+=lb(pos)){
		ta[pos] += num;
	}
}
inline LL ps(LL pos){
	LL ans=0;
	for(; pos; pos-=lb(pos)){
		ans += ta[pos];
	}	
	return ans;
}
inline LL lrs(LL l, LL r){
	return ps(r) - ps(l-1);
}
inline LL find(LL num){
	LL pos=0, sum=0;
	for(LL p=lg2[n]; p>=0; p--){
		if(pos+(1<<p)<=n && sum+ta[pos+(1<<p)]<num){
			sum += ta[pos+(1<<p)];
			pos += (1<<p);
		}
	}
	pos++;
	return pos;
}
inline void init(){
	lg2[0] = -1;
	lg2[1] = 0;
	for(LL i=2; i<MAX; i++){
		lg2[i] = lg2[i>>1] + 1;
	}
}

signed main(){
	init();
	RLL(n);
	for(LL i=1; i<=n; i++){
		add(i,1);
	}
	pre[1]=0;
	for(LL i=2; i<=n; i++){
		RLL(pre[i]);
	}
	for(LL i=n; i>1; i--){
		LL rank = pre[i];
		rank++;
		LL num = find(rank);
		add(num, -1);
		ans[i] = num;
	}
	ans[1] = find(1);
	for(LL i=1; i<=n; i++){
		printf("%lld\n", ans[i]);
	}
}
