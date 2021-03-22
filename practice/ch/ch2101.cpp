#include <iostream>
#include <queue>
#include <bitset>
#include <vector>
using namespace std;
#define RI(x) scanf("%d", &x)

bitset<30005> can[30005];
queue<int> q;

int head[30005], to[30005], nx[30005];
int cnt=0;

int in[30005];

void addedge(int x, int y){
	to[++cnt] = y;
	nx[cnt] = head[x];
	head[x] = cnt;
	in[y]++;
}

vector<int> tos;

int main(){
	int n,m;
	RI(n);
	RI(m);
	int x,y;
	for(int i=0; i<m; i++){
		RI(x);
		RI(y);
		addedge(x,y);
	}

	for(int i=1; i<=n; i++){

		//cout << i << ' ' << in[i] << endl;

		if(in[i]==0){
			q.push(i);
		}
	}
	while(q.size()){
		int node = q.front();

		//cout << node << endl;

		q.pop();
		tos.push_back(node);
		for(int edge=head[node]; edge!=0; edge=nx[edge]){
			in[to[edge]]--;
			if(in[to[edge]]==0){
				q.push(to[edge]);
			}
		}
	}

	//for(auto i : tos){
	//	cout << i << ' ';
	//}
	//cout << endl;
	
	for(int i=1; i<=n; i++){
		can[i][i] = 1;
	}
	for(int i=tos.size()-1; i>=0; i--){
		for(int e=head[i]; e!=0; e=nx[e]){
			can[i] |= can[to[e]];
		}
	}
	for(int i=1; i<=n; i++){
		printf("%d\n", can[i].count());
	}
}
