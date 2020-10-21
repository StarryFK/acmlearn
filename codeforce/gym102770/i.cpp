#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;


map<int,int> id;
int idcnt=0;

int fa[100005];
int tot[100005];

int getid(int i){
	if(id.count(i)){
		return id[i];
	}else{
		return id[i] = idcnt++;
	}
}

int getr(int i){
	if(fa[i]==i){
		return i;
	}else{
		return fa[i] = getr(fa[i]);
	}
}

void merge(int i, int j){
	fa[getr(i)] = getr(j);
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		id.clear();
		idcnt=0;
		memset(tot, 0, sizeof(tot));
		for(int i=0; i<100005; i++){
			fa[i] = i;
		}
		int n;
		scanf("%d", &n);
		int a,b;
		for(int i=0; i<n; i++){
			scanf("%d %d", &a, &b);
			merge(getid(a), getid(b));
		}
		int result=0;
		for(int i=0; i<idcnt; i++){

			//cout << getr(i) << endl;

			tot[getr(i)]++;
		}
		for(int i=0; i<idcnt; i++){
			result = max(result, tot[i]);
		}
		printf("%d\n", result);
	}
}
