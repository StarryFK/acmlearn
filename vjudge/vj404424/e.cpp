#include <iostream>
#include <cstring>
#define MAXN 200005
using namespace std;

int x[MAXN]; 
int t[MAXN]; 
int C[MAXN]; 
int p[MAXN]; 
int c[MAXN]; 

int xp=0;
int tp=0;
int Cp=0;
int pp=0;
int cp=0;

int xtop=0;
int ttop=0;
int Ctop=0;
int ptop=0;
int ctop=0;

int main(){
	int n;
	while(cin >> n){
		memset(x,0,sizeof(x));
		memset(t,0,sizeof(t));
		memset(C,0,sizeof(C));
		memset(p,0,sizeof(p));
		memset(c,0,sizeof(c));
		char ch;
		for(int i=0; i<n; i++){
			cin >> ch;
			if(ch=='x'){
				x[xtop++] = i;
			}else if(ch=='t'){
				t[ttop++] = i;
			}else if(ch=='C'){
				C[Ctop++] = i;
			}else if(ch=='p'){
				p[ptop++] = i;
			}else if(ch=='c'){
				c[ctop++] = i;
			}
		}
		int cnt=0;

		//for(int i=0; i<xtop; i++){
		//	cout << x[i] << ' ';
		//}
		//cout << endl;
		//for(int i=0; i<ttop; i++){
		//	cout << t[i] << ' ';
		//}
		//cout << endl;
		//for(int i=0; i<Ctop; i++){
		//	cout << C[i] << ' ';
		//}
		//cout << endl;
		//for(int i=0; i<ptop; i++){
		//	cout << p[i] << ' ';
		//}
		//cout << endl;
		//for(int i=0; i<ctop; i++){
		//	cout << c[i] << ' ';
		//}
		//cout << endl;

		for(xp=0; xp<xtop; xp++){
			int i=x[xp];
			while(t[tp] < i && tp<ttop){
				tp++;
			}
			if(tp>=ttop){
				break;
			}else{
				i = tp++;
			}
			while(C[Cp] < i && Cp<Ctop){
				Cp++;
			}
			if(Cp>=Ctop){
				break;
			}else{
				i = Cp++;
			}
			while(p[pp] < i && pp<ptop){
				pp++;
			}
			if(pp>=ptop){
				break;
			}else{
				i = pp++;
			}
			while(c[cp] < i && cp<ctop){
				cp++;
			}
			if(cp>=ctop){
				break;
			}else{
				i = cp++;
			}

			//cout << xp << tp << Cp << pp << cp << endl;

			cnt++;
		}
		cout << cnt << '\n';
	}
}
