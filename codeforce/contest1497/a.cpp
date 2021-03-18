#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define RI(x) scanf("%d", &x)

int cnt[200];

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		memset(cnt, 0, sizeof(cnt));
		int n;
		cin >> n;
		int tmp;
		for(int i=0; i<n; i++){
			cin >> tmp; 
			cnt[tmp]++;
		}
		bool ok=1;
		while(ok){
			ok=0;
			for(int i=0; i<200; i++){
				if(cnt[i]){
					cout << i << ' ';
					cnt[i]--;
					ok=1;
				}
			}
		}
		cout << endl;
	}
}

