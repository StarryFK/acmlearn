#include <iostream>
#include <cmath>
#define ll long long
#define ull unsigned long long
using namespace std;


int main(){
    ll pos=0, neg=0, now, pri=0, num;
    cin >> num;
    cin >> pri;
    for(int i=1; i<num; i++){
        cin >> now;
        if(now-pri>0){
            pos += now-pri;
        }else{
            neg += pri-now;
        }
        pri = now;
    }
    cout << max(pos, neg) << endl;
    cout << (pos-neg>0 ? pos-neg : neg-pos)+1 << endl;
}