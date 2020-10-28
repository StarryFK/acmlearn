#include <iostream>
#include <utility>
#include <map>
#include <cstring>
using namespace std;

int diff[10005];
map<pair<int, int>, bool> vis;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,i,h,r;
    cin >> n >> i >> h >> r;
    memset(diff, 0, sizeof(diff));
    int x,y;
    for(int i=0; i<r; i++){
        cin >> x >> y;
        if(x>y){
            swap(x,y);
        }
        if(vis.count(make_pair(x,y))){
            continue;
        }
        vis[make_pair(x,y)] = true;
        diff[x]--;
        diff[y-1]++;
    }
    int cur=h;

    // for(int i=0; i<n; i++){
    //     cout << diff[i] << endl;
    // }
    // cout << endl;

    for(int i=0; i<n; i++){
        cur += diff[i];
        cout << cur << '\n';
    }
}