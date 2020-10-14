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
	srand(clock());
	for(int i=0; i<10; i++){
		cout << rand() << '\n';
	}
}
