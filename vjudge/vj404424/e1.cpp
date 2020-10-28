#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <queue>
#define RI(x) scanf("%d", &x)
#define RC(x) scanf("%c", &x)
using namespace std;

queue<int> index[5];

map<char, int> id;

int main(){
	id['x'] = 0;
	id['t'] = 1;
	id['C'] = 2;
	id['p'] = 3;
	id['c'] = 4;
	int n;
	//while(~RI(n)){
	RI(n);
		for(int i=0; i<5; i++){
			while(!index[i].empty()){
				index[i].pop();
			}
		}
		char ch;
		getchar();
		for(int i=0; i<n; i++){
			RC(ch);

			//cout << ch << endl;
			if(id.count(ch)){
				index[id[ch]].push(i);
			}
		}

		//for(int i=0; i<5; i++){
		//	cout << "index";
		//	for(int j=0; j<top[i]; j++){
		//		cout << index[i][j] << ' ';
		//	}
		//	cout << endl;
		//}

		int tot=0;
		while(!index[0].empty()){
			int i= index[0].front();
			for(int j=1; j<5; j++){
				while(index[j].front() < i && !index[j].empty()){
					index[j].pop();
				}
				if(index[j].empty()){
					goto out;
				}
				i = index[j].front();
			}
			tot++;
			for(int j=0; j<5; j++){
				index[j].pop();
			}
		}
out:
		printf("%d\n", tot);
	//}
}
