#include <iostream>
#include <cstdio>
using namespace std;
const double eps = 1e-8;

double vec[15][15];
double a[15][15], b[15];

int main(){
	int n;
	cin >> n;
	for(int i=0; i<n+1; i++){
		for(int j=0; j<n; j++){
			cin >> vec[i][j];
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			a[i][j] = 2 * (vec[i][j] - vec[i+1][j]);
			b[i] += vec[i][j]*vec[i][j] - vec[i+1][j]*vec[i+1][j];
		}
	}
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			if(a[j][i]>eps){
				for(int k=0; k<n; k++){
					swap(a[j][k], a[i][k]);
				}
				swap(b[j], b[i]);
				break;
			}
		}
		for(int j=0; j<n; j++){
			if(i==j){
				continue;
			}
			double rate = a[j][i] / a[i][i];
			for(int k=0; k<n; k++){
				a[j][k] -= rate * a[i][k];
			}
			b[j] -= rate * b[i];
		}
	}
	for(int i=0; i<n; i++){
		if(i>0){
			cout << ' ';
		}
		printf("%.3f", b[i] / a[i][i]);
	}
}
