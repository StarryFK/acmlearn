#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;
#define IINF 0x3f3f3f3f

vector<int> to[26];
bool visit[26];
bool appear[26];
int buf[10];
int ans[10];
int minb=IINF;
int cnt=0;

bool read(){
	for(int i=0; i<26; i++){
		to[i].clear();
	}
	memset(appear, 0, sizeof(appear));
	char ch=0;
	while(ch!='\n'){
		ch = getchar();
		if(ch=='#'){
			return false;
		}
		int x = ch-'A';
		appear[x]=1;
		getchar();
		for(ch=getchar();ch>='A' && ch<='Z'; ch=getchar()){
			int y = ch-'A';
			appear[y]=1;
			to[x].push_back(y);
			to[y].push_back(x);
		}
	}
	return true;
}

bool check(int i, int j){
	for(auto t : to[i]){
		if(t==j){
			return true;
		}
	}
	return false;
}

void calc(){
	int bid=0;
	for(int i=0; i<cnt; i++){
		for(int j=0; j<cnt; j++){
			if(i!=j && check(buf[i],buf[j])){
				bid = max(bid, abs(i-j));
			}
		}
	}
	if(bid < minb){
		for(int i=0; i<cnt; i++){
			ans[i] = buf[i];
		}
		minb = bid;
	}
}

void dfs(int cur){
	if(cur==cnt){
		calc();
		return;
	}
	for(int i=0; i<26; i++){
		if(appear[i] && !visit[i]){
			buf[cur] = i;
			visit[i]=1;
			dfs(cur+1);
			visit[i]=0;
		}
	}
}

int main(){
	while(read()){
		cnt=0;
		for(int i=0; i<26; i++){
			if(appear[i]){
				cnt++;
			}
		}
		minb=IINF;
		dfs(0);
		for(int i=0; i<cnt; i++){
			printf("%c ", ans[i]+'A');
		}
		printf("-> %d\n", minb);
	}
}

