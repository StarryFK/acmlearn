#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
double y;
double e = exp(1);
double a,b;

int find1(double l, double r){
	if(abs(l-r)<1e-5){
		if(abs(round(l)-l)<1e-5){
			return round(l);
			//if(abs(l-e)<1e-6 ||abs(l-0)<1e-6){
			//	return 0;
			//}else{
			//	return round(l);
			//}
		}else{
			return 0;
		}
	}
	double mid = (l+r)/2.0;
	double pown = pow(mid, 1.0/mid);
	if(pown > a/b){
		return find1(l,mid);
	}else{
		return find1(mid,r);
	}
}

int find2(double l, double r){
	if(abs(l-r)<1e-5){
		if(abs(round(l)-l)<1e-5){
			//if(abs(l-1e18)<1e-6 ||abs(l-e)<1e-6){
			//	return 0;
			//}else{
			//	return round(l);
			//}
			return round(l);
		}else{
			return 0;
		}
	}
	double mid = (l+r)/2.0;
	double pown = pow(mid, 1.0/mid);
	if(pown < a/b){
		return find2(l,mid);
	}else{
		return find2(mid,r);
	}
}

int main(){

	//printf("%.17lf", pow(1e18,1.0/1e18));

	while(cin >> a >> b){
		y = pow((double)a, 1.0/b);

		//cout << y << endl;

		int x1,x2;
		if(y>e){
			cout << 0 << endl;
			continue;
		}else{
			x1 = find1(0.0,e);
			x2 = find2(e, 1e18);
		}

		//cout << x1 << ' ' << x2 << endl;

		if(x1!=0 && x2!=0){
			cout << x1 << endl;
		}else{
			cout << max(x1, x2) << endl;
		}
	}
}
