#include <iostream>
#include <algorithm>
#define INF 0x3f3f3f3f
#include <cmath>
#include <vector>
#include <cstdio>
#define RI(x) scanf("%d", &x)
#define ull unsigned long long
#define ll long long
using namespace std;

struct Inv{
	double l;
	double r;
	Inv(double _l, double _r){
		l = _l;
		r = _r;
	}
};

bool operator < (const Inv &a, const Inv &b){
	return a.l < b.l;
}

vector<Inv> v;

int main(){
	int n,d;
	int kase=0;
	while(RI(n)){
		if(n==0){
			break;
		}
		RI(d);
		int x,y;
		v.clear();
		bool flag=true;
		for(int i=0; i<n; i++){
			RI(x);
			RI(y);
			if(d<y){
				flag=false;
			}
			if(flag==true){
				v.push_back(Inv(x-sqrt(d*d-y*y), x+sqrt(d*d-y*y)));
			}
		}
		if(flag==false){
			printf("Case %d: -1\n", ++kase);
			continue;
		}
		sort(v.begin(), v.end());

		//for(auto i : v){
		//	cout << i.l << ' ' << i.r << endl;
		//}

		double pos = (double)-INF;
		int cnt=0;
		for(int i=0; i<v.size(); i++){
			if(pos<v[i].l){
				cnt++;
				pos = v[i].r;
			}else{
				pos = min(v[i].r, pos);
			}
		}
		printf("Case %d: %d\n", ++kase, cnt);
	}
}
