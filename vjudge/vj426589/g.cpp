#include <iostream>
#include <cmath>
using namespace std;

const double PI = acos(-1);

double x,y,l,w;

double cal(double in){
	return (l*sin(in)+w/(cos(in))-x)/tan(in);
}

int main(){
	ios::sync_with_stdio(false);
	while(cin>>x>>y>>l>>w){
		double ll=0, rr=PI/2;
		double midl, midr;
		while(rr-ll>1e-6){
			midl = (2*ll+rr)/3;
			midr = (2*rr+ll)/3;
			if(cal(midl) < cal(midr)){
				ll = midl;
			}else{
				rr = midr;
			}
		}

		//cout << cal(ll) << endl;

		if(cal(ll) <= y){
			puts("yes");
		}else{
			puts("no");
		}
	}
}
