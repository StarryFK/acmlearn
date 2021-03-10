#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define RI(x) scanf("%d", &x)

bool vis[2005][2005];
int arr[3][2005];
int line;

struct Con{
	int x;
	int y;
	Con(int a, int b){
		x=a;
		y=b;
	}
};

bool operator<(const Con &a, const Con &b){
	return arr[line&1][a.x]+arr[2][a.y] > arr[line&1][b.x]+arr[2][b.y];
}

priority_queue<Con> q;

inline void clearq(){
	while(!q.empty()){
		q.pop();
	}
}

int main(){
	int t;
	RI(t);
	while(t--){
		int n,m;
		RI(m);
		RI(n);
		for(int i=0; i<n; i++){
			RI(arr[1][i]);
		}
		sort(arr[1], arr[1]+n);
		for(line=1; line<m; line++){
			for(int i=0; i<n; i++){
				RI(arr[2][i]);
			}
			sort(arr[2], arr[2]+n);

			//for(int i=0; i<n; i++){
			//	cout << arr[line&1][i] << ' ';
			//}
			//cout << endl;
			//for(int i=0; i<n; i++){
			//	cout << arr[2][i] << ' ';
			//}
			//cout << endl;

			clearq();
			q.push(Con(0,0));
			memset(vis, 0, sizeof(vis));
			for(int i=0; i<n; i++){
				int x=q.top().x;
				int y=q.top().y;

				//cout << x << ' ' << y << endl;

				q.pop();
				if(!vis[x+1][y]){
					vis[x+1][y]=1;
					q.push(Con(x+1, y));
				}
				if(!vis[x][y+1]){
					vis[x][y+1]=1;
					q.push(Con(x, y+1));
				}
				arr[!(line&1)][i] = arr[line&1][x] + arr[2][y];
			}
		}
		for(int i=0; i<n; i++){
			printf("%d ", arr[line&1][i]);
		}
		puts("");
	}
}
