#include <iostream>
#include <vector>

using namespace std;

vector<int> out;
int n,m;

void dfs(int now){
    if(out.size()==m){
        for(int i : out){
            cout << i << ' ';
        }
        cout << '\n';
    }else{
        if(out.size()==m || out.size()+(n-now+1)<m){
            return;
        }
        out.push_back(now);
        dfs(now+1);
        out.pop_back();
        dfs(now+1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    dfs(1);
}