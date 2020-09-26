#include <iostream>
#include <utility>
#include <cmath>
#define ull unsigned long long

using namespace std;

ull n,h,o;

pair<ull, ull> calc(ull n, ull m){
    if(n==0){
        return make_pair(0,0);
    }
    ull len = 1<<(n-1);
    ull cnt = 1<<(2*n-2);
    pair<ull, ull> in = calc(n-1, m%cnt);
    ull x = in.first;
    ull y = in.second;
    int pos = m/cnt;
    if(pos==0){
        return make_pair(y,x);
    }else if(pos==1){
        return make_pair(x, y+len);
    }else if(pos==2){
        return make_pair(len+x, len+y);
    }else{
        return make_pair(len*2-y-1, len-x-1);
    }
}


int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> h >> o;
        pair<ull, ull> pos1 = calc(n, h-1), pos2 = calc(n, o-1);
        double x1=pos1.first*10, y1=pos1.second*10, x2=pos2.first*10, y2=pos2.second*10;
        //cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
        ull d = round(sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)));
        cout << d << '\n';
    }
}