#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
#define RI(x) scanf("%d", &x)
#define INF 0x3f3f3f3f

struct Node{
	vector<int> to;
};

bool label[100005];
bool visit[100005];
bool ans[100005];
Node tree[100005];
set<int> cs;

bool dfs(int cur, bool fs){
	visit[cur] = true;
	bool inset = cs.count(cur);
	int connect=fs;
	if(inset){

		//cout << cur << "inset" << endl;

		fs=1;
		connect++;
		label[cur]=1;
		ans[cur]=1;
	}
	for(auto i : tree[cur].to){
		if(!visit[i]){
			//cout <<cur << ':' << i << ' ';
			connect += dfs(i, fs);
		} 
	}
	if(connect>=2){
		label[cur]=1;
	}

	//cout << cur << ":" << connect  << endl;

	return label[cur]?1:0;
}

int main(){
	int n,k;
	RI(n);
	RI(k);
	for(int h=0; h<n-1; h++){
		int i,j,w;
		RI(i);
		RI(j);
		RI(w);
		tree[i].to.push_back(j);
		tree[j].to.push_back(i);
	}
	for(int i=0; i<k; i++){
		int x;
		RI(x);
		cs.insert(x);
	}
	dfs(1,0);
	for(auto i : cs){
		for(int j=0; j<(int)tree[i].to.size(); j++){
			if(label[tree[i].to[j]]){
				ans[tree[i].to[j]]=1;
			}
		}
	}
	int cnt=0;
	for(int i=1; i<=n; i++){
		if(label[i]){
			cnt++;
		}
	}
	printf("%d", cnt);
}
