#include <iostream>
using namespace std;
#define ULL unsigned long long

const ULL p[]={2,3,5,7,11,13,17,19,23,29};
ULL ppow[10][31];
ULL n;
ULL ansn=0;
ULL anscnt=0;
void dfs(ULL step, ULL lim, ULL num, ULL cnt){

	//cout << step << ' ' << num << ' ' << cnt << endl;

	if(num>n){
		return;
	}
	if(step==10){
		return;
	}
	if(cnt>anscnt || (cnt==anscnt && num<ansn)){
		ansn = num;
		anscnt = cnt;
	}
	for(int i=lim; i>=1; i--){
		dfs(step+1, i, num*ppow[step][i], cnt*(i+1));
	}
}
void init(){
	for(int i=0; i<10; i++){
		ppow[i][0]=1;
	}
	for(int i=0; i<10; i++){
		for(int j=1; j<=30; j++){
			ppow[i][j] = ppow[i][j-1]*p[i];
		}
	}
}

int main(){
	init();
	cin >> n;
	dfs(0, 30, 1, 1);
	cout << ansn << endl;
}
