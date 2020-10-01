#include <bits/stdc++.h>
using namespace std;

string s;

bool check(int l, int r){
    while(l<r){
        if(s[l]!=s[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    cin >> s;
    int len=0;
    for(int i=0; i<n; i++){
        if(check(i,n-1)){
            //cout << 1 << endl;
            //cout << n << ' ' << i << endl;
            len = n-i;
            //cout << len << endl;
            break;
        }
    }
    cout << n-len << endl;
}
