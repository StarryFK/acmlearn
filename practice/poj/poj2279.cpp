#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define RLL(x) scanf("%lld", &x)
#define LL long long

LL n[6];

int main(){
	LL k;
	while(1){
		RLL(k);
		if(k==0){
			break;
		}
		memset(n, 0, sizeof(n));
		for(LL i=0; i<k; i++){
			RLL(n[i]);
		}
		LL dp[n[0]+1][n[1]+1][n[2]+1][n[3]+1][n[4]+1];
		memset(dp, 0, sizeof(dp));
		dp[0][0][0][0][0]=1;
		for(LL a=0; a<=n[0]; a++){
			for(LL b=0; b<=n[1]; b++){
				for(LL c=0; c<=n[2]; c++){
					for(LL d=0; d<=n[3]; d++){
						for(LL e=0; e<=n[4]; e++){
							if(a<n[0]){
								dp[a+1][b][c][d][e] += dp[a][b][c][d][e];
							}							
							if(b<n[1] && b<a){
								dp[a][b+1][c][d][e] += dp[a][b][c][d][e];
							}							
							if(c<n[2] && c<b){
								dp[a][b][c+1][d][e] += dp[a][b][c][d][e];
							}							
							if(d<n[3] && d<c){
								dp[a][b][c][d+1][e] += dp[a][b][c][d][e];
							}							
							if(e<n[4] && e<d){
								dp[a][b][c][d][e+1] += dp[a][b][c][d][e];
							}							
						}
					}
				}
			}
		}
		printf("%lld\n", dp[n[0]][n[1]][n[2]][n[3]][n[4]]);
	}
}
