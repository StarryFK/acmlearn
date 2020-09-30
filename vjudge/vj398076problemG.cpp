#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int cnt[100005][15];
int maxcnt[100005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(cnt, 0, sizeof(cnt));
    memset(maxcnt, 0, sizeof(maxcnt));
    int n,q;
    int l,r,x;
    string op;
    cin >> n >> q;
    for(int i=0; i<q; i++){
        cin >> op;
        if(op[1]=='U'){
            cin >> l >> r >> x;
            for(int j=l; j<=r; j++){
                if(x==2 || x==3 || x==5 || x==7){
                    cnt[j][x]++;
                    maxcnt[j] = max(cnt[j][x], maxcnt[j]);
                }else if(x==4){
                    cnt[j][2] += 2;
                    maxcnt[j] = max(cnt[j][2], maxcnt[j]);
                }else if(x==6){
                    cnt[j][2]++;
                    maxcnt[j] = max(cnt[j][2], maxcnt[j]);
                    cnt[j][3]++;
                    maxcnt[j] = max(cnt[j][3], maxcnt[j]);
                }else if(x==8){
                    cnt[j][2] += 3;
                    maxcnt[j] = max(cnt[j][2], maxcnt[j]);
                }else if(x==9){
                    cnt[j][3] += 2;
                    maxcnt[j] = max(cnt[j][3], maxcnt[j]);
                }else if(x==10){
                    cnt[j][2]++;
                    maxcnt[j] = max(cnt[j][2], maxcnt[j]);
                    cnt[j][5]++;
                    maxcnt[j] = max(cnt[j][5], maxcnt[j]);
                }
            }
        }else{
            int result=0;
            cin >> l >> r;
            for(int j=l; j<=r; j++){
                result = max(result, maxcnt[j]);
            }
            cout << "ANSWER " << result << '\n';
        }
    }
}