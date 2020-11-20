#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<int> s;
stack<int> getmin;

int main(){
	string str;
	int num;
	while(cin >> str){
		if(str[1]=='u'){
			cin >> num;
			s.push(num);
			if(getmin.empty()){
				getmin.push(num);
			}else{
				if(num < getmin.top()){
					getmin.push(num);
				}else{
					getmin.push(getmin.top());
				}
			}
		}else if(str[1]=='o'){
			cout << s.top() << endl;
			s.pop();
			getmin.pop();
		}else{
			cout << getmin.top() << endl;
		}
	}
}
