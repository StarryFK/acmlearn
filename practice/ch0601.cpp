#include <iostream>
#include <cstring>
#include <algorithm>
#define ull unsigned long long
#define RI(x) scanf("%d", &x)
#define RULL(x) scanf("%llu", &x)

using namespace std;

ull arr[500005];
ull tmp[500005];
ull mtmp[500005];
ull n,m,k;

void merge(int l, int r, int rp){
	sort(tmp+r+1, tmp+rp+1);
	int k=l, i=l, j=r+1;
	while(i<=r && j<=rp){
		if(tmp[i] < tmp[j]){
			mtmp[k++] = tmp[i++];
		}else{
			mtmp[k++] = tmp[j++];
		}
	}
	while(i<=r){
		mtmp[k++] = tmp[i++];
	}
	while(j<=rp){
		mtmp[k++] = tmp[j++];
	}
	memcpy(tmp+l, mtmp+l, sizeof(ull*(k-1)));
}

ull getR(int l){
	ull r = l;
	ull p = 1;
	tmp[l] = arr[l];
	while(p!=0){
		if(r+p>=n){
			p /= 2;
			continue;
		}
		memcpy(tmp+r+1, arr+r+1, sizeof(p*ull))
		merge(l,r,r+p);
		ull sum=0;
		for(ull i=0; i<m; i++){
			sum += (tmp[r+p-i] - tmp[l+i]) *(tmp[r+p-i] - tmp[l+i])
			if(sum > k){
				break;
			}
		}
		if(sum <= k){
			r += p;
			p *= 2;
		}else{
			p /= 2;
		}
	}
	return r;
}

int main(){
	int t;
	RI(t);
	while(t--){
		RULL(n);
		RULL(m);
		RULL(k);
		for(ull i=0; i<n; i++){
			RULL(arr[i]);
		}
		int cnt=1;
		while(getR(0)!=n){
			cnt++;
		}
		printf("%d\n", cnt);
	}
}
