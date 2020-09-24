#include <iostream>
#include <vector>

using namespace std;

vector<int> out;
int n;

void dfs(int now){
    if(now>n){
        for(int i : out){
            cout << i << ' ';
        }
        cout << '\n';
    }else{
        dfs(now+1);
        out.push_back(now);
        dfs(now+1);
        out.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    dfs(1);
}