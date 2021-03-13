#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define RI(x) scanf("%d", &x)

const int E5 = 1e5+5;

int arr[E5];

int main(){
	int n,m;
	RI(n);
	RI(m);
	int maxn=0;
	for(int i=0; i<n; i++){
		RI(arr[i]);
		maxn = max(maxn, arr[i]);
	}
	int l=maxn, r=1e9;
	while(l<r){
		int mid = (l+r)>>1;
		int group=0, tot=0;
		for(int i=0; i<n; i++){
			if(tot+arr[i] <= mid){
				tot += arr[i];
			}else{
				group++;
				tot = arr[i];
			}
		}
		if(tot){
			group++;
		}

		//cout << mid << ' ' << group << endl;

		if(group > m){
			l = mid+1;
		}else{
			r = mid;
		}
	}
	printf("%d\n", l);
}
