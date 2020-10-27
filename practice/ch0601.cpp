#include <iostream>
#include <cstdio>
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

void merge(ull l, ull r, ull rp){
	sort(tmp+r+1, tmp+rp+1);

	//for(int i=l; i<=rp; i++){
	//	cout << tmp[i] << ' ';
	//}
	//cout << endl;

	ull p=l, i=l, j=r+1;
	while(i<=r && j<=rp){
		if(tmp[i] < tmp[j]){
			mtmp[p++] = tmp[i++];
		}else{
			mtmp[p++] = tmp[j++];
		}
	}
	while(i<=r){
		mtmp[p++] = tmp[i++];
	}
	while(j<=rp){
		mtmp[p++] = tmp[j++];
	}
	
	//cout << "mtmp\n";
	//for(ull q=l; q<=rp; q++){
	//	cout << mtmp[q] << ' ';
	//}
	//cout << endl;
	
	//memcpy(tmp+l, mtmp+l, sizeof(ull)*p);
}

ull getR(int l){


	//cout << "l:" << l << ' ';

	ull r = l;
	ull p = 1;
	tmp[l] = arr[l];
	while(p!=0){


		//cout << "p:" << p << " r:"<<r << ' ';

		if(r+p>=n){
			p /= 2;
			continue;
		}

		//cout << endl;
		//for(ull i=l; i<=r+p; i++){
		//	cout << tmp[i] << ' ';
		//}
		//cout << endl;

		memcpy(tmp+r+1, arr+r+1, sizeof(ull)*p);

		//cout << endl << "tmp" << endl;
		//for(ull i=l; i<=r+p; i++){
		//	cout << tmp[i] << ' ';
		//}
		//cout << endl;

		merge(l,r,r+p);

		//cout << endl;
		//cout << "mtmp" << endl;
		//for(ull i=l; i<=r+p; i++){
		//	cout << mtmp[i] << ' ';
		//}
		//cout << endl;

		ull sum=0;
		for(ull i=0; i<m; i++){
			if(r+p-i <= l+i){
				break;
			}
			sum += (mtmp[r+p-i] - mtmp[l+i]) *(mtmp[r+p-i] - mtmp[l+i]);
			if(sum > k){
				break;
			}
		}

		//cout << "sum:" << sum << ' ';

		if(sum <= k){
			memcpy(tmp+l, mtmp+l, sizeof(ull)*(r+p-l+1));
			r += p;
			p *= 2;
		}else{
			p /= 2;
		}
	}

	//cout << endl;

	return r;
}

int main(){
	int t;
	RI(t);
	while(t--){
		RULL(n);
		RULL(m);
		RULL(k);

		//cout << t << endl;

		for(ull i=0; i<n; i++){
			RULL(arr[i]);
		}
		int cnt=1;
		ull r=0;
		while((r=getR(r)+1) < n){
			cnt++;

			//cout << "r " << r << endl;

		}
		printf("%d\n", cnt);
	}
}
