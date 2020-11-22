#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>
#define RI(x) scanf("%d", &x)
using namespace std;

vector<int> to[2000005];
int visit[2000005];
map<int, int> id;
int ids=0;
int name[2000005];
vector<int> out;

inline int getid(int num){
	if(id.count(num)){
		return id[num];
	}else{
		name[ids] = num;
		id[num] = ids++;
		return ids-1;
	}
}

void dfs(root){
	visit[root]++;
	if(visit[root]>=to[root].size()){
		if(out.size() = m+1){
			printf("%d\n", out.size(:))
		}
	}
}

int main(){
	int m;
	while(~RI(m)){
		for(int i=0; i<m; i++){
			to[i].clear();
		}
		id.clear();
		out.clear();
		ids=0;
		memset(visit, 0, sizeof(visit));
		memset(name, 0, sizeof(name));
		int x,y;
		for(int i=0; i<m; i++){
			RI(x);
			RI(y);
			to[getid(x)] = getid(y);
			to[getid(y)] = getid(x);
		}
		int cnt=0;
		int root=0;
		for(int i=0; i<ids; i++){
			if(to[i].size()%2==0){
				cnt++;
			}else{
				root = i;
			}
		}
		if(ids-cnt!=2 || ids-cnt!=0){
			puts("-1");
			continue;
		}
		dfs(root);
	}
}

