#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <map>
using namespace std;
#define LL long long
#define int LL
#define RLL(x) scanf("%lld", &x)
const LL MAXN = 1E6+5;

vector<pair<LL, LL> > prob;
LL fa[MAXN];
map<LL, LL> m;

inline void init(LL size){
	for(int i=0; i<=size; i++){
		fa[i]=i;
	}
}
LL getfa(LL node){
	if(node==fa[node]){
		return node;
	}else{
		return fa[node]=getfa(fa[node]);
	}
}
inline void merge(LL a, LL b){
	fa[getfa(a)] = getfa(b);
}
inline LL gett(LL num){
	if(m.count(num)==0){
		m[num]=m.size();
	}
	return m[num];
}

signed main(){
	LL t;
	RLL(t);
	while(t--){
		prob.clear();
		m.clear();
		LL n;
		RLL(n);
		init(2*n);
		while(n--){
			LL i,j,e;
			RLL(i);
			RLL(j);
			RLL(e);
			if(e==1){
				merge(gett(i),gett(j));
			}else{
				prob.push_back(make_pair(gett(i), gett(j)));
			}
		}
		bool ans=1;
		for(vector<pair<LL, LL> >::iterator it=prob.begin(); it!=prob.end(); it++){
			if(getfa(it->first) == getfa(it->second)){
				ans=0;
				break;
			}
		}
		printf("%s\n", ans ? "YES" : "NO");
	}
}