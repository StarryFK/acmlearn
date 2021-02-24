#include <iostream>
#include <cstdio>
using namespace std;
const int EE6=1e6+5;

bool b[EE6];

int main(){
	int n;
	scanf("%d", &n);
	getchar();
	bool last = 0;
	int in;
	for(int i=0; i<n; i++){
		in = getchar()-'0';

		//cout << last << ' ' << in << ' ';

		if(in==last){
			printf("0");
		}else{
			printf("1");
			if(last==0){
				last=1;
			}
		}

		//cout << endl;
	}
}
