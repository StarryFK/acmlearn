#include <iostream>
#include <cstring>
#include <map>
#define ull unsigned long long
using namespace std;

const int mod = 1e9+7;

ull x[65];
ull w[100005];
map<ull, int> bi;

bool mis(int pos, ull n){
    //cout << pos << endl;
    if(x[pos] >= n){
        //cout << x[pos] << ' ';
        x[pos] -= n;
        //cout << x[pos] << endl;
        return true;
    }else{
        if(pos==0){
            return false;
        }
        n -= x[pos];
        x[pos]=0;
        return mis(pos-1, n*2);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ull a=1;
    for(int i=0; i<63; i++){
        bi[(a<<i)] = i;
    }

    while(cin >> x[0]){
        int n;
        for(int i=1; i<60; i++){
            cin >> x[i];
        }

       // for(int i=1; i<=60; i++){
       //     cout << x[i-1] << ' ';
       //     if(i%20==0){
       //         cout << endl;
       //     }
       // }

        cin >> n;
        ull result = 0;
        for(int i=0; i<n; i++){
            cin >> w[i];
        }
        bool flag=true;
        for(int i=0; i<n; i++){                
            while(w[i]){
                if(!mis(bi[w[i]&(-w[i])], 1)){
                    cout << -1 << '\n';
                    goto next;
                }
                w[i] -= w[i]&(-w[i]);
            }
        }

       // for(int i=1; i<=60; i++){
       //     cout << x[i-1] << ' ';
       //     if(i%20==0){
       //         cout << endl;
       //     }
       // }

        for(int i=0; i<60; i++){                
            result = (result*2 + x[59-i])%mod;
        }
        cout << result << '\n';
        next:;
    }
}