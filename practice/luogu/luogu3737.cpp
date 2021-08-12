#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct Point{
	double x,y;
};
bool operator < (const Point &a, const Point &b){
	return a.x < b.x;
}
vector<Point> v;
int n;
double R;
inline double offset(double y){
	return sqrt(R*R-y*y);
}

int main(){
	cin >> n >> R;
	for(int i=0; i<n; i++){
		double x,y;
		cin >> x >> y;
		v.push_back({x,y});
	}
	sort(v.begin(), v.end());
	int count=0;
	double last = -1e6;
	for(auto i : v){
		double os = offset(i.y);
		double l = i.x - os;
		double r = i.x + os;
		if(l>last){
			count++;
			last = r;
		}else{
			last = min(last, r);
		}
	}
	cout << count << endl;
}
