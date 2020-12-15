#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string str;


int main(){
	cin >> str;
	bool side=0;
	int p[2]={0,0}, g[2]={0,0};
	for(int i=0; i<(int)str.length(); i++){
		char ch = str[i];
		if(ch=='S'){
			p[side]++;
		}else if(ch=='R'){
			side = !side;
			p[side]++;
		}else{
			if(g[0]==2 || g[1]==2){
				printf("%d %s- %d%s\n", g[0], (g[0]>g[1]?"(winner) ":""), g[1], (g[1]>g[0]?" (winner)":""));
			}else{
				printf("%d (%d%c) - %d (%d%c)\n", g[0], p[0], (side==0?'*':0), g[1], p[1], (side==1?'*':0));
			}
		}
		if(abs(p[0]-p[1])>=2 && (p[0]>=5 || p[1]>=5)){
			if(p[0] > p[1]){
				g[0]++;
				p[0]=0;
				p[1]=0;
			}else{
				g[1]++;
				p[0]=0;
				p[1]=0;
			}
		}else if(p[0]==10 || p[1]==10){
			if(p[0]==10){
				g[0]++;
				p[0]=0;
				p[1]=0;
			}else{
				g[1]++;
				p[0]=0;
				p[1]=0;
			}
		}
	}
}
