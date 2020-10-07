#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int field[100005];
double f2[100005];

int main(){
    ios::sync_with_stdio(false);
    int n,f;
    cin >> n >> f;
    for(int i=1; i<=n; i++){
        cin >> field[i];
    }
    double eps=1e-5, l=0.0, r=2e3+9;
    while(r-l>eps){
        double mid = (l+r)/2;
        //cout << "mid" << mid << endl;
        for(int i=1; i<=n; i++){
            f2[i] = field[i] - mid;
        }
        for(int i=2; i<=n; i++){
            f2[i] = f2[i-1] + f2[i];
        }
        double minsum=1e10, maxsum=-1e10;
        for(int i=f; i<=n; i++){
            minsum = min(minsum, f2[i-f]);
            maxsum = max(maxsum, f2[i] - minsum);
        }
        if(maxsum>=0){
            l = mid;
        }else{
            r = mid;
        }
    }
    cout << int(r*1000) << endl;
}