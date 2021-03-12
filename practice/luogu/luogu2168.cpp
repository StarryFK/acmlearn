#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
#define LL long long
#define RLL(x) scanf("%lld", &x)

const int E5 = 1e5+5;

struct HN{
	LL time;
	LL val;
	LL tn;
};

bool operator < (const HN &a, const HN &b){
	if(a.val != b.val){
		return a.val > b.val;
	}else{
		return a.time > b.time;
	}
}

priority_queue<HN> heap;

struct TN{
	vector<LL> son;
	LL rc=-1;
} tree[E5*2];

LL totnode=0;

LL arr[E5];

int maxdep = 0;

LL dfs(int addr, int dep){

	//cout << addr << ' ' << dep << ' ' << tree[addr].rc << endl;

	if(tree[addr].rc!=-1){
		maxdep = max(maxdep, dep);
		return arr[tree[addr].rc] * dep;
	}
	LL ans=0;
	for(auto i : tree[addr].son){
		ans += dfs(i, dep+1);
	}
	return ans;
}

int main(){
	LL n,k;
	RLL(n);
	RLL(k);
	for(int i=0; i<n; i++){
		LL w;
		RLL(w);
		arr[i] = w;
		tree[totnode].rc = i;
		heap.push({1,w,totnode});
		totnode++;
	}
	while((heap.size()-1)%(k-1)){
		heap.push({1,0,-1});
	}
	while(heap.size()>1){
		LL newtime=0;
		LL newval=0;
		for(int i=0; i<k; i++){
			newtime = max(newtime, heap.top().time);
			newval += heap.top().val;
			if(heap.top().tn!=-1){
				tree[totnode].son.push_back(heap.top().tn);
			}

			//cout << heap.top().val << ' ' << heap.top().time << endl;

			heap.pop();
		}
		heap.push({newtime+1, newval, totnode});
		totnode++;
	}
	LL ans = dfs(totnode-1, 0);
	printf("%lld\n%d\n", ans, maxdep);
}
