#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define LL long long
#define int LL
#define RLL(x) scanf("%lld", &x)

struct Pro{
	LL p;
	LL d;
	Pro(LL x, LL y){
		p=x;
		d=y;
	}
};
vector<Pro> v;
LL fa[10005];

bool operator < (const Pro &a, const Pro &b){
	return a.p > b.p;
}
LL getfa(LL node){
	if(fa[node]==node){
		return node;
	}else{
		return fa[node]=getfa(fa[node]);
	}
}
inline void merge(LL a, LL b){
	fa[getfa(a)] = getfa(b);
}
inline void init(){
	for(LL i=0; i<10005; i++){
		fa[i]=i;
	}
}

signed main(){
	LL n;
	while(~RLL(n)){
		v.clear();
		init();
		LL p,d;
		for(LL i=0; i<n; i++){
			RLL(p);
			RLL(d);
			v.push_back(Pro(p,d));
		}
		sort(v.begin(), v.end());
		LL ans=0;
		for(LL i=0; i<n; i++){
			LL head = getfa(v[i].d);
			if(head>0){
				merge(head, head-1);
				ans += v[i].p;
			}
		}
		printf("%lld\n", ans);
	}
}