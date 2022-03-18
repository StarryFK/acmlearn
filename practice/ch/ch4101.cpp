#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define LL long long
#define int LL
#define RLL(x) scanf("%lld", &x)
const LL MAX = 30005;

LL fa[MAX];
LL d[MAX];
LL size[MAX];

inline void init(){
	for(LL i=0; i<MAX; i++){
		fa[i]=i;
		d[i]=0;
		size[i]=1;
	}
}
LL getfa(LL node){
	if(fa[node]==node){
		return node;
	}else{
		LL root = getfa(fa[node]);
		d[node] += d[fa[node]];
		return fa[node] = root;
	}
}
inline void merge(LL a, LL b){
	a = getfa(a);
	b = getfa(b);
	fa[a] = b;
	d[a] += size[b];
	size[b] += size[a];
}

signed main(){
	LL t;
	RLL(t);
	init();
	while(t--){
		char op;
		LL i,j;
		getchar();
		op = getchar();
		RLL(i);
		RLL(j);
		if(op=='M'){
			merge(i,j);
		}else{
			if(getfa(i)==getfa(j)){
				printf("%lld\n", abs(d[i]-d[j])-1);
			}else{
				puts("-1");
			}
		}
	}
}