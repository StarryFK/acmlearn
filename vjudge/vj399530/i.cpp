#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


int dp[505][505][505];

struct Card{
    int w;
    int x;
    bool m;
    bool s;

    bool operator<(Card obj){
        if(m!=obj.m){
            return m>obj.m;
        }else{
            if(s!=obj.s){
                return s<obj.s;
            }else{
                return (double)x/w > (double)obj.x/obj.w;
            }
        }
    }
};

Card c[505];

int main(){
    ios::sync_with_stdio(false);

    int n,W;
    cin >> n >> W;
    for(int i=1; i<n; i++){
        cin >> c[i].w >> c[i].x >> c[i].m >> c[i].s;
    }
    sort(c, c+n);
    memset(dp, 0xcf, sizeof(dp));
    dp[0][W][0] = 0;
    for(int pos=1; pos<=n; pos++){
        for(int wrest=0; wrest<=W; wrest--){
            for(int mrest=0; mrest<=n; mrest++){
                dp[pos][wrest][mrest] = dp[pos-1][wrest][mrest];
            }
        }
        for(int wrest=0; wrest<=W-c[pos].w; wrest++){
            for(int mrest=0; mrest<=n; mrest++){
                dp[pos][wrest][mrest] = max(dp[pos][wrest][mrest], dp[pos-1][wrest+c[pos].w][mrest] + c[pos].x);
            }
            if(c[pos].m && !c[pos].s)
            for(int mrest=1; mrest<=n; mrest++){
                dp[pos][wrest][mrest] = max(dp[pos][wrest][mrest], dp[pos-1][wrest+c[pos].w][mrest-1] + c[pos].x);
            }
        }
        for(int wrest=0; wrest+c[pos].w-1<=W; wrest++){
            if(!c[pos].m && c[pos].s)
            for(int mrest=0; mrest+1<=n; mrest++){
                dp[pos][wrest][mrest] = max(dp[pos][wrest][mrest], dp[pos-1][wrest+c[pos].w][mrest+1] + c[pos].x);
            }
            if(c[pos].m && c[pos].s)
            for(int mrest=0; mrest<=n; mrest++){
                dp[pos][wrest][mrest] = max(dp[pos][wrest][mrest], dp[pos-1][wrest+c[pos].w-1][mrest] + c[pos].x);
            }
        }
    }
    int ans=0;
    for(int i=0; i<=500; i++){
        for(int j=0; j<=500; j++){
            ans = max(ans, dp[n][i][j]);
        }
    }
    cout << ans << '\n';
}