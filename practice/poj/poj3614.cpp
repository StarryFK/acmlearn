#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define RI(x) scanf("%d", &x)
using namespace std;

struct Cow{
	int minspf;
	int maxspf;

	Cow(int a, int b){
		minspf = a;
		maxspf = b;
	}
};

struct Bottle{
	int spf;
	int cnt;

	Bottle(int a, int b){
		spf = a;
		cnt = b;
	}
};

bool operator <(const Cow &a, const Cow &b){
	return a.maxspf < b.maxspf;
}

bool operator <(const Bottle &a, const Bottle &b){
	return a.spf < b.spf;
}

vector<Bottle> bottle;
vector<Cow> cow;

int main(){
	int c,l;
	while(~RI(c)){
		RI(l);
		int tmp1, tmp2;
		bottle.clear();
		cow.clear();
		for(int i=0; i<c; i++){
			RI(tmp1);
			RI(tmp2);
			cow.push_back(Cow(tmp1, tmp2));
		}
		for(int i=0; i<l; i++){
			RI(tmp1);
			RI(tmp2);
			bottle.push_back(Bottle(tmp1, tmp2));
		}
		sort(bottle.begin(), bottle.end());
		sort(cow.begin(), cow.end());
		int result=0;
		for(unsigned int i=0; i<cow.size(); i++){
			
			//cout << "cow" << cow[i].minspf <<' ' << cow[i].maxspf <<  endl;

			for(unsigned int j=0; j<bottle.size(); j++){
				if(bottle[j].spf <= cow[i].maxspf && bottle[j].spf >= cow[i].minspf && bottle[j].cnt>0){

					//cout << "bottle" << bottle[j].spf <<' ' << bottle[j].cnt << endl;

					bottle[j].cnt--;
					result++;
					break;
				}
			}
		}
		printf("%d\n", result);
	}
}
