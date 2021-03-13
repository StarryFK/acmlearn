#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define RI(x) scanf("%d", &x)

int arr[50005];

int main(){
	int L,n,m;
	RI(L);
	RI(n);
	RI(m);
	for(int i=0; i<n; i++){
		RI(arr[i]);
	}
	sort(arr, arr+n);
	arr[n] = L;
	int l=1, r=(int)1e9;
	while(l<r){
		int cnt=0;
		int last=0;
		int mid = (l+r+1)>>1;

		//cout << "dis: " << mid << endl;

		for(int i=0; i<=n; i++){

			//cout << arr[i]-last << ' ';

			if(arr[i]-last >= mid){
				last = arr[i];
			}else{
				cnt++;
			}
		}

		//cout << endl << cnt << endl;

		if(cnt > m){
			r = mid-1;
		}else{
			l = mid;
		}
	}
	printf("%d\n", l);
}
