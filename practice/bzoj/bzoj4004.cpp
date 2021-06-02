#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define LD long double
#define RI(x) scanf("%d", &x)
#define RLD(x) scanf("%Lf", &x)
const LD eps = 1e-6;

LD a[505][505], v[505];

bool eq(LD x, LD y){
	return abs(x-y) < eps;
}

int main(){
	int n,m;
	RI(n);
	RI(m);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			RLD(a[i][j]);
		}
	}
	for(int i=0; i<n; i++){
		RLD(v[i]);
	}
	int dimcnt = 0;
	LD cost = 0;
	for(int i=0; i<m; i++){

		//for(int i=0; i<n; i++){
		//	for(int j=0; j<m; j++){
		//		cout << a[i][j] << ' ' ;
		//	}
		//	cout << endl;
		//}
		//cout << endl;

		int found = -1;
		LD fv = 2000;
		for(int j=dimcnt; j<n; j++){
			if(!eq(a[j][i], 0.0) && v[j]<fv){
				found = j;
				fv = v[j];
			}
		}
		if(found==-1){
			continue;
		}
		cost += fv;
		for(int k=0; k<m; k++){
			swap(a[found][k], a[dimcnt][k]);
		}
		swap(v[found], v[dimcnt]);
		for(int j=0; j<n; j++){
			if(dimcnt==j){
				continue;
			}
			LD rate = a[j][i] / a[dimcnt][i];
			for(int k=0; k<m; k++){
				a[j][k] -= rate * a[dimcnt][k];
			}
		}
		dimcnt++;

		//for(int i=0; i<n; i++){
		//	for(int j=0; j<m; j++){
		//		cout << a[i][j] << ' ' ;
		//	}
		//	cout << endl;
		//}
		//cout << endl;

	}
	printf("%d %.0Lf\n", dimcnt, cost);
}
