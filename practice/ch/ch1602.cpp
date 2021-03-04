#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define RI(x) scanf("%d\n", &x)
#define INF 0x3f3f3f3f
const int E5 = 1e5+5;

int trie[31*E5][2];
int tot=0;
int arr[E5];

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
	int ans=0;
	int p=0;
	for(int i=31; i>=0; i--){
		if(trie[p][!getbit(num, i)]){
			ans += (1<<i);
			p = trie[p][!getbit(num, i)];
		}else{
			p = trie[p][getbit(num,i)];
		}
	}
	return ans;
}

int main(){
	int n;
	RI(n);
	for(int i=0; i<n; i++){
		RI(arr[i]);
		insert(arr[i]);
	}
	int ans = -INF;
	for(int i=0; i<n; i++){
		ans = max(ans, getMax(arr[i]));
	}
	printf("%d\n", ans);
}
