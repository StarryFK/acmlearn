#include <iostream>
#include <cstdio>
#define ull unsigned long long 
#define RI(x) scanf("%d", &x)
using namespace std;

int arr[500005];
int tmp[500005];
ull cnt=0;

void bin(int l, int r){
	if(l==r){
		return;
	}
	int mid = (l+r)>>1;
	bin(l, mid);
	bin(mid+1, r);
	int k=0, i=l, j=mid+1;
	
	//cout << l << ' ' << r << endl;

	while(i<=mid && j<=r){
		//cout << i << ' ' << j << endl;
		if(arr[i]<=arr[j]){
			tmp[k++] = arr[i++];
		}else{
			cnt += mid-i+1;

			//cout <<"cnt"<< cnt << endl;

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
		arr[p] = tmp[p-l];
	}
}

int main(){
	int n;
	while(~RI(n)){
		if(n==0){
			break;
		}
		for(int i=0; i<n; i++){
			RI(arr[i]);

			//cout << arr[i] << ' ';

		}

		//cout << endl;

		cnt=0;
		bin(0,n-1);
		printf("%llu\n", cnt);

		//for(int i=0; i<n; i++){
		//	cout << arr[i] << ' ';
		//}
		//cout << endl;

	}
}
