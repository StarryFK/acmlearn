#include <iostream>
#include <stack>
#include <set>
#include <string>
#include <vector>
using namespace std;

stack<int> st;
vector<int> out;
int n;
string buf;
int cnt=0;

void dfs(int cur){
	if(cnt>=20){
		return;
	}
	if(out.size()==n){
		for(int i=0; i<out.size(); i++){
			cout << out[i];
		}	
		cout << endl;
		cnt++;
	}
	if(!st.empty()){
		out.push_back(st.top());
		st.pop();
		dfs(cur);
		st.push(out[out.size()-1]);
		out.pop_back();
	}
	if(cur<=n){
		st.push(cur);
		dfs(cur+1);
		st.pop();
	}
}

int main(){
	cin >> n;
	dfs(1);
}

