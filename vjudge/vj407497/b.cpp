#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
#define RI(x) scanf("%d", &x)
using namespace std;

int r[1000];
int k,R;

double calc(double x){
	double sum=0;
	for(int i=0; i<k; i++){
		sum += (r[i]*x)/(r[i]+x);
	}
	return sum;
}

double find(double l, double rr){
	if(abs(l-rr)<1e-7){
		if(abs(l-1e18)>1e-7 && abs(l-0)>1e-7){
			return l;
		}else{
			return -1;
		}
	}
	double mid = (l+rr)/2;
	if(calc(mid) < R){
		return find(mid, rr);
	}else{
		return find(l, mid);
	}
}

int main(){
	while(~RI(k)){
		RI(R);
		for(int i=0; i<k; i++){
			RI(r[i]);
		}
		double ans = find(0, 1e18);
		printf("%.6lf\n", ans);
	}
}
