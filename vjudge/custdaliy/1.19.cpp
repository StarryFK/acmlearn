#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define RI(x) scanf("%d", &x)
#define INF 0x3f3f3f3f
const int E5 = 2e5+5;

int arr[E5];
int maxl[E5], minl[E5];
int maxr[E5], minr[E5];

int main(){
	int t;
	RI(t);
	while(t--){
		int n,m;
		RI(n);
		RI(m);
		getchar();
		int x=0;
		for(int i=1; i<=n; i++){
			if(getchar()=='+'){
				x++;
			}else{
				x--;
			}
			arr[i] = x;

			//cout << x << ' ';

		}

		//cout << endl;

		int curmax = 0;
		int curmin = 0;
		for(int i=1; i<=n; i++){
			curmax = max(curmax, arr[i]);
			curmin = min(curmin, arr[i]);
			maxl[i] = curmax;
			minl[i] = curmin;
		}
		curmax = -INF;
		curmin = INF;
		for(int i=n; i>0; i--){
			curmax = max(curmax, arr[i]);
			curmin = min(curmin, arr[i]);
			maxr[i] = curmax;
			minr[i] = curmin;
		}

		//for(int i=1; i<=n; i++){
		//	cout << maxl[i] << ' ';
		//}
		//cout << endl;
		//for(int i=1; i<=n; i++){
		//	cout << minl[i] << ' ';
		//}
		//cout << endl;
		//for(int i=1; i<=n; i++){
		//	cout << maxr[i] << ' ';
		//}
		//cout << endl;
		//for(int i=1; i<=n; i++){
		//	cout << minr[i] << ' ';
		//}
		//cout << endl;

		int l,r;
		for(int i=0; i<m; i++){
			RI(l);
			RI(r);
			int minv=0, maxv=0;
			if(l>1){
				minv = min(minv, minl[l-1]);
				maxv = max(maxv, maxl[l-1]);
			}
			if(r<n){
				int sum = arr[r] - arr[l-1];
				minv = min(minv, minr[r+1]-sum);
				maxv = max(maxv, maxr[r+1]-sum);
			}
			printf("%d\n", maxv-minv+1);
		}
	}
}
