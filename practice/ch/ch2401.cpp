#include <iostream>
#include <functional>
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
#define LL long long
#define RLL(x) scanf("%lld", &x)

LL arr[50];
vector<LL> pw;
set<LL> pws;
LL w,n;
LL ans = 0;

void dfs1(int cur, LL dst, LL tot){
	if(tot>w){
		return;
	}
	pws.insert(tot);
	if(cur>dst){
		return;
	}
	dfs1(cur+1, dst, tot);
	dfs1(cur+1, dst, tot+arr[cur]);
}

void dfs2(int cur, LL dst, LL tot){
	if(tot>w){
		return;
	}
	ans = max(ans, tot + *(upper_bound(pw.begin(), pw.end(), w-tot)-1));
	if(cur>dst){
		return;
	}
	dfs2(cur+1, dst, tot);
	dfs2(cur+1, dst, tot+arr[cur]);
}

int main(){
	RLL(w);
	RLL(n);
	for(LL i=0; i<n; i++){
		RLL(arr[i]);
	}
	sort(arr, arr+n, greater<int>());
	dfs1(0, n/2, 0);
	for(auto i : pws){
		pw.push_back(i);
	}
	dfs2(n/2+1, n-1, 0);
	printf("%lld\n", ans);
}
