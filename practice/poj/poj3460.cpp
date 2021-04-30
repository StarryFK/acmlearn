#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int arr[20];
int n;
int barr[5][20];
inline int getf(){
	int ans=0;
	for(int i=0; i<n-1; i++){
		if(arr[i]!=arr[i+1]-1){
			ans++;
		}
	}
	if(arr[n-1]!=n){
		ans++;
	}
	return (ans+2)/3;
}
bool dfs(int cur, int lim){
	int f = getf();
	if(f==0){
		return true;
	}
	if(cur+f>lim){
		return false;
	}
	memcpy(barr[cur], arr, sizeof(arr));
	for(int l=0; l<n; l++){
		for(int r=l; r<n; r++){
			for(int k=r+1; k<n; k++){
				memcpy(arr, barr[cur], sizeof(arr));
				
				//cout << l << ' ' << r << ' ' << k << endl;
				//for(int i=0; i<n; i++){
				//	cout << barr[cur][i] << ' ';
				//}
				//cout << endl;

				int p=r+1;
				for(int i=l; i<=k; i++){
					arr[i] = barr[cur][p++];
					if(p>k){
						p=l;
					}
				}

				//for(int i=0; i<n; i++){
				//	cout <<  arr[i] << ' ';
				//}
				//cout << endl;

				if(dfs(cur+1, lim)){
					return true;
				}
			}
		}
	}
	return false;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=0; i<n; i++){
			cin >> arr[i];
		}
		for(int d=0; d<=4; d++){
			if(dfs(0,d)){
				cout << d << endl;
				goto nx;
			}
		}
		cout << "5 or more" << endl;
nx:;
	}
}
