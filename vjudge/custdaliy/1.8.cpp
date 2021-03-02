#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int i=0; i<t; i++){
		unsigned long long n;
		cin >> n;
		cout << "Case #" << i+1 << ": " << ((2+n)*(n-1)/2) << '\n';
	}
}
