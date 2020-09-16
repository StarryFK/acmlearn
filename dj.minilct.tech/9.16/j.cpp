#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int m=0, y=0, f=0;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='m'){
            m++;
        }else if(s[i]=='y'){
            y++;
        }else if(s[i]=='f'){
            f++;
        }
    }
    int myf = min(m,min(y,f));
    int mm = m/2;
    if(myf>mm){
        cout << "myfsdyp!" << endl;
    }else if(myf<mm){
        cout << "mmhpl!" << endl;
    }else{
        cout << "yuandijiehun!" << endl;
    }
}