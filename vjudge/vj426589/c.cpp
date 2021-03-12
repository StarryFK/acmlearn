include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

const double PI = acos(-1);

inline double eq(double a, double b){
	return abs(a-b) < 1e-6;
}

int main(){
	double L,N,C;
	while(1){
		cin >> L >> N >> C;
		if(L<0){
			break;
		}
		double l=0, r=L/2;

		//cout << (1+N*C)*L << endl;

		while(!eq(l,r)){
			double mid = (l+r)/2;

			//cout << mid << endl;

			double a = atan(L/2/mid);
			double b = PI-2*a;
			double R = L/2/sin(b);
			double Lp = 2*b*R;

			//cout << Lp << endl;

			if(Lp < (1+N*C)*L){
				l=mid;
			}else{
				r=mid;
			}
		}
		printf("%.3f\n", l);

		//cout << endl;

	}
}
