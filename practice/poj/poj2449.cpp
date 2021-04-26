#include <iostream>
#include <cstring>
#include <utility>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
#define RLL(x) scanf("%lld", &x)
#define LL long long
#define INF 0x3f3f3f3f 
#define LINF 0x3f3f3f3f3f3f3f3f

struct St{
	LL point;
	LL dis;
	LL val;
};
bool operator<(const St &a, const St &b){
	return a.dis+a.val > b.dis+b.val;
}
priority_queue<St> pq;
LL valvis[1005];
LL vcnt[1005];
vector<pair<LL, LL> > to[1005];
vector<pair<LL, LL> > rto[1005];
LL val[1005];
LL n,m;
LL S,T,K;
inline void getval(){
	val[T] = 0;
	pq.push({T,0,0});
	while(pq.size()){
		LL x=pq.top().point;
		pq.pop();
		if(valvis[x]){
			continue;
		}
		valvis[x]=1;
		for(LL i=0; i<rto[x].size(); i++){
			LL y = rto[x][i].first;
			LL z = rto[x][i].second;
			if(val[y] > val[x] + z){
				val[y] = val[x] + z;
				pq.push({y, val[y], 0});
			}
		}
	}
	while(pq.size()){
		pq.pop();
	}
}
inline LL bfs(){
	pq.push({S, 0, val[S]});
	while(pq.size()){
		LL x = pq.top().point;
		LL dis = pq.top().dis;
		pq.pop();
		//cout << x << ' ' << dis << ' ' << vcnt[x] << endl;
		vcnt[x]++;
		if(vcnt[T]==K){
			return dis;
		}
		for(LL i=0; i<to[x].size(); i++){
			LL y = to[x][i].first;
			LL z = to[x][i].second;
			if(vcnt[y]<K){
				pq.push({y, dis+z, val[y]});
				//cout << "push " << y << ' ' << dis+z << ' ' << val[y] << endl;
			}
		}
	}
	return -1;
}
inline void init(){
	memset(val, 0x3f, sizeof(val));
}
int main(){
	init();
	RLL(n);
	RLL(m);
	for(LL i=0; i<m; i++){
		LL a,b,t;
		RLL(a);
		RLL(b);
		RLL(t);
		to[a].push_back({b, t});
		rto[b].push_back({a, t});
	}
	RLL(S);
	RLL(T);
	RLL(K);
	if(S==T){
		K++;
	}
	getval();
	printf("%lld\n", bfs());
}
