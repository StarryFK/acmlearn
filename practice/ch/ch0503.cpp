#include <iostream>
#include <cstdio>
#define RI(x) scanf("%d", &x)
using namespace std;

int arr[250010];
int tmp[250010];

long long cnt=0;
void msort(int l, int r){
	if(l==r) return;
	int mid = (l+r)>>1;
	msort(l, mid);
	msort(mid+1, r);
	int k=l, i=l, j=mid+1;
	while(i<=mid && j<=r){
		if(arr[i]<=arr[j]){
			tmp[k++] = arr[i++];
		}else{
			cnt += mid-i+1;
			tmp[k++] = arr[j++];
		}
	}
	while(i<=mid){
		tmp[k++] = arr[i++];
	}
	while(j<=r){
		tmp[k++] = arr[j++];
	}
	for(int p=l; p<=r; p++){
		arr[p] = tmp[p];
	}
}

int main(){
	int n;
	while(~RI(n)){

		//cout << "start"  << n << endl;

		if(n==1){
			
			//cout << "here" << endl;

			RI(arr[0]);
			RI(arr[0]);
			puts("TAK");
			continue;
		}
		for(int i=0, pos=0; i<n*n; i++,pos++){
			RI(arr[pos]);
			if(arr[pos]==0){
				pos--;
			}

			//cout << arr[i] << endl;
		}
		cnt=0;
		msort(0, n*n-2);
		long long cnt1 = cnt;

		//for(int i=0; i<n*n-1; i++){
		//	cout << arr[i] << ' ';
		//}
		//cout << endl;

		for(int i=0, pos=0; i<n*n; i++,pos++){
			RI(arr[pos]);

			//cout << arr[pos] << endl;

			if(arr[pos]==0){
				pos--;
			}


		}
		cnt=0;
		msort(0, n*n-2);
		long long cnt2 = cnt;

		//for(int i=0; i<n*n-1; i++){
		//	cout << arr[i] << ' ';
		//}
		//cout << endl;
		
		//cout << cnt1 << ' ' << cnt2 << endl;

		if((cnt1%2) == (cnt2%2)){
			puts("TAK");
		}else{
			puts("NIE");
		}
	}
}
