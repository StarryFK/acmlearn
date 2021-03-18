#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define RI(x) scanf("%d", &x)

int arr[2][100005];

int main(){
	int t;
	RI(t);
	while(t--){
		int n,m;
		RI(n);
		RI(m);
		memset(arr, 0, sizeof(arr));
		int tmp;
		for(int i=0; i<n; i++){
			RI(tmp);
			arr[0][tmp%m]++;
			arr[1][m - (tmp%m)]++;
		}
		int ans = 0;
		if(arr[0][0]!=0){
			ans++;
		}
		if(m%2==0 && arr[0][m/2]!=0){
			ans++;
		}
		for(int i=1; i<=m/2; i++){
			if(i==m/2 && m%2==0){
				break;
			}
			int d = min(arr[0][i], arr[1][i]);
			if(d!=0){
				arr[0][i] -= d;
				arr[1][i] -= d;
				ans++;
				if(arr[0][i]!=0){
					arr[0][i]--;
				}
				if(arr[1][i]!=0){
					arr[1][i]--;
				}
			}
			ans += max(arr[0][i], arr[1][i]);
		}
		printf("%d\n", ans);
	}
}
