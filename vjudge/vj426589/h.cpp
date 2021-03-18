#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double x,y,v;
const double g = 9.8;
const double PI = acos(-1);

double cal(double ag){
	return x*tan(ag) - (g*x*x)/(2*v*v*cos(ag)*cos(ag));
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> x >> y >> v;
		double l=0, r=PI/2;
		double midl, midr;
		while(r-l>1e-8){
			midl = (l+l+r)/3;
			midr = (r+r+l)/3;
			if(cal(midl) < cal(midr)){
				l = midl;
			}else{
				r = midr;
			}
		}
		if(cal(l) >= y){
			r=l, l=0;
			double mid;
			while(r-l>1e-8){
				mid = (l+r)/2;
				if(cal(mid) < y){
					l = mid;
				}else{
					r = mid;
				}
			}
			printf("%.6f\n", l);
		}else{
			cout << -1 << '\n';
		}
	}
}
