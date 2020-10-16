#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>
#define ull unsigned long long 
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a=0;

	for(int i=0; i<1000; i++){
		for(int i=0; i<1000; i++){
			cout << 1 << '\n';
		}
		a = rand();
	}

	for(int i=0; i<1000; i++){
		cout << 1 << '\n';
		cout << 2 << '\n';
	}

	cout << a << '\n';
}

