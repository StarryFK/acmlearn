#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
#define RI(x) scanf("%d", &x)
#define INF 0x3f3f3f3f

struct Node{
	vector<int> to;
	vector<int> w;
};

bool label[100005];
bool visit[100005];
Node tree[100005];

int main(){
	int k,n;
	RI(n);
	RI(k);
	for(int p=0; p<n-1; p++){
		int i,j,w;
		RI(i);
		RI(j);
		RI(w);
		tree[i].to.push_back(j);
		tree[i].w.push_back(w);
		tree[j].to.push_back(i);
		tree[j].w.push_back(w);
	}
	for(int i=0; i<k; i++){
		int x;
		RI(x);
		label[x]=1;
		int minn=INF, minx=0;
		for(int j=0; j<(int)tree[x].to.size(); j++){
			if(tree[x].w[j]<minn){
				minn=tree[x].w[j];
				minx=tree[x].to[j];
			}else if(tree[x].w[j]==minn){
				minx=0;
			}
		}
		label[minx]=1;

		//cout <<' '<< minx << endl;

	}
	int cnt=0;
	for(int i=1; i<=n; i++){
		if(label[i]){
			cnt++;
		}
	}
	printf("%d\n", cnt);
}
