#include <iostream>
#include <cmath>
using namespace std;

double calc(double x){
	return 8*pow(x,4) + 7*pow(x,3) + 2*pow(x,2) + 3*x + 6;
}

double eq(double a, double b){
	return abs(a-b) < 1e-6;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		double y;
		cin >> y;
		double l=0, r=100;
		for(int i=0; i<100; i++){
			double mid = (l+r)/2;

			//cout << mid << endl;

			if(calc(mid) < y){
				l = mid;
			}else{
				r = mid;
			}
		}

		//printf("%.10f, %.10f\n", calc(l), y);

		if(eq(calc(l), y)){
			printf("%.4f\n", l);
		}else{
			puts("No solution!");
		}
	}
}
