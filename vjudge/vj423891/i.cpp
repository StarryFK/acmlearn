#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	n /= 2;
	for(int i=1; i<=sqrt(n); i++){
		if(n%i==0){
			v.push_back(i);
			if(n/i!=i){
				v.push_back(n/i);
			}
		}
	}
	cout << v.size() << '\n';
	sort(v.begin(), v.end());
	for(auto i : v){
		cout << i << ' ';
	}
	cout << '\n';
}
