#include <iostream>
#include <cmath>
#define ull unsigned long long 
#include <algorithm>
#include <cstring>
using namespace std;

int xcnt[100005];
int ycnt[100005];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n,m,t;
	cin >> n >> m >> t;
	int x,y;
	memset(xcnt, 0, sizeof(xcnt));
	memset(ycnt, 0, sizeof(ycnt));
	for(int i=1; i<=t; i++){
		cin >> x >> y;
		xcnt[x]++;
		ycnt[y]++;
	}

//	for(int i=1; i<=n; i++){
//		cout << xcnt[i] << ' ' ;
//	}
//	cout << endl;
//	for(int i=1; i<=m; i++){
//		cout << ycnt[i] << ' ' ;
//	}
//	cout << endl;

	bool row,col;
	if(t%n==0){
		row=true;
	}else{
		row=false;
	}
	if(t%m==0){
		col=true;
	}else{
		col=false;
	}
	ull result=0;
	if(row){
		for(int i=1; i<=n; i++){
			xcnt[i] -= t/n;
		}
		for(int i=2; i<=n; i++){
			xcnt[i] += xcnt[i-1];
		}
		sort(xcnt+1, xcnt+n+1);
		int mid = (n+1)/2;
		for(int i=1; i<=n; i++){
			result += abs(xcnt[i] - xcnt[mid]);
		}
	}
	if(col){
		for(int i=1; i<=m; i++){
			ycnt[i] -= t/m;
		}
		for(int i=2; i<=m; i++){
			ycnt[i] += ycnt[i-1];
		}
		sort(ycnt+1, ycnt+m+1);
		int mid = (m+1)/2;
		for(int i=1; i<=m; i++){
			result += abs(ycnt[i] - ycnt[mid]);
		}
	}

//	for(int i=1; i<=n; i++){
//		cout << xcnt[i] << ' ' ;
//	}
//	cout << endl;
//	for(int i=1; i<=m; i++){
//		cout << ycnt[i] << ' ' ;
//	}
//	cout << endl;

	if(col && row){
		cout << "both " << result<<'\n';
	}else if(col){
		cout << "column " << result<<'\n';
	}else if(row){
		cout << "row " << result<<'\n';
	}else{
		cout << "impossible\n";
	}
}
