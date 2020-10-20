#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>
#define ull unsigned long long 
using namespace std;

int arr[105];

int main(){
	int n;
	int i=0;
	while(cin >>n){
		arr[i++] = n;
	}
	for(int j=i-2; j>-1; j--){
		cout << arr[j] <<' ';
	}
	cout << endl;
}

