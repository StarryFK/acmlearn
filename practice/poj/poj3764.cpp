#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
#include <map>
using namespace std;
#define RI(x) scanf("%d", &x)
const int E5 = 1e5+5;

int trie[31*E5][2];
int tot;
vector<pair<int, int> > out[E5];

inline int getbit(int num, int pos){
	return (num<<pos)&1;
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
	return ans;
}

void dfs(int cur, int csum){
	insert(csum);
	for(auto i : out[cur]){
		dfs(i.first, csum^i.second);
	}
}

int main(){
	int n;
	while(~RI(n)){
		memset(trie, 0, sizeof(trie));
		tot=0;
		for(int i=0; i<n; i++){
			out[i].clear();
		}
		for(int )
	}
}
