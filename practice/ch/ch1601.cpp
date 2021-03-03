#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define RI(x) scanf("%d", &x)
#define RS(x) scanf("%s", x)
const int E6 = 1e6+5;

char str[E6];
int trie[E6][26];
int tot=0;
int eend[E6];

void insert(){
	int len = strlen(str);
	int p=0;
	for(int i=0; i<len; i++){
		if(trie[p][str[i]-'a']==0){
			trie[p][str[i]-'a'] = ++tot;
		}
		p = trie[p][str[i]-'a'];
	}
	eend[p]++;
}

int search(){
	int len = strlen(str);
	int p=0;
	int ans=0;
	for(int i=0; i<len; i++){
		if(trie[p][str[i]-'a']==0){
			break;
		}
		ans += eend[p];
		p = trie[p][str[i]-'a'];
	}
	ans += eend[p];
	return ans;
}

int main(){
	int n,m;
	RI(n);
	RI(m);
	for(int i=0; i<n; i++){
		RS(str);
		insert();
	}

	//cout << tot << endl;

	for(int i=0; i<m; i++){
		RS(str);
		printf("%d\n", search());
	}
}
