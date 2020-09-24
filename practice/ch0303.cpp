#include <iostream>
#include <vector>
using namespace std;

int visit[15];
vector<int> out;

int n;

void dfs(int now){
    if(out.size()==n){
        for(int i:out){
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=1; i<=n; i++){
        if(!visit[i]){
            out.push_back(i);
            visit[i]=true;
            dfs(now+1);
            visit[i]=false;
            out.pop_back();
        }
    }
}

int main(){
    cin >> n;
    dfs(1);
}
