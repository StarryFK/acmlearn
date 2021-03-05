#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;
#define RI(x) scanf("%d", &x)
const int E5 = 1e5+5;

int trie[31*E5][2];
int tot;
int arr[E5];
bool visit[E5];

struct Edge{
	int to;
	int w;
	int next;
} edge[2*E5];
int ecnt;
int head[E5];


inline void clearh(int num){
	memset(head, 0, num*sizeof(int));
	memset(edge, 0, 2*num*sizeof(Edge));
	ecnt=0;
}

inline void addedge(int u, int v, int w){
	edge[++ecnt] = {v, w, head[u]};
	head[u] = ecnt;
	edge[++ecnt] = {u, w, head[v]};
	head[v] = ecnt;
}

inline int getbit(int num, int pos){
	return (num>>pos)&1;
}

void insert(int num){
	int p=0;
	for(int i=31; i>=0; i--){
		if(trie[p][getbit(num, i)]==0){
			trie[p][getbit(num, i)] = ++tot;
		}
		p = trie[p][getbit(num, i)];
	}
}

int getMax(int num){
	int p=0;
	int ans=0;
	for(int i=31; i>=0; i--){
		if(trie[p][!getbit(num, i)]){
			ans += (1<<i);
			p = trie[p][!getbit(num, i)];
		}else{
			p = trie[p][getbit(num, i)];
		}
	}

	//cout << num << ' ' << ans << endl;

	return ans;
}

void dfs(int cur, int csum){
	insert(csum);
	arr[cur] = csum;

	//cout << cur <<' ' << csum << endl;

	for(int p=head[cur]; p!=0; p=edge[p].next){
		if(visit[edge[p].to]){
			continue;
		}
		visit[edge[p].to]=1;
		dfs(edge[p].to, csum^edge[p].w);
		visit[edge[p].to]=0;
	}
}

int main(){
	int n;
	while(~RI(n)){
		memset(trie, 0, 32*2*n*sizeof(int));
		memset(arr, 0, n*sizeof(int));
		memset(visit, 0, n*sizeof(bool));
		tot=0;
		clearh(n);
		int u,v,w;
		for(int i=0; i<n-1; i++){
			RI(u);
			RI(v);
			RI(w);
			addedge(u,v,w);
		}
		visit[0]=1;
		dfs(0,0);
		int ans = 0;

		//cout << ans << endl;

		for(int i=0; i<n; i++){
			ans = max(getMax(arr[i]), ans);
		}
		printf("%d\n", ans);
	}
}
