include <vector>
#define ull unsigned long long
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> v;

int main(){
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	int mid = (v.size()%2==0) ? v.size()/2 : (v.size()-1)/2;
	ull sum=0;
	for(int i=0; i<v.size(); i++){
		sum += abs(v[mid]-v[i]);
	}
	cout << sum << '\n';
}
