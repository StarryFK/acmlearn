#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int mark[45][45];
char ma[45][45];

string coll[25];

char buf[25];

bool sig[1<<22];

int main(){

	for(int i=0; i<22; i++){
		sig[1<<i]=true;
	}
	sig[0]=true;

	int l,c;
	cin >> l >> c;
	for(int i=0; i<l; i++){
		for(int j=0; j<c; j++){
			cin >> ma[i][j];
		}
	}
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> coll[i];
		sort(coll[i].begin(), coll[i].end());
	}
	for(int i=0; i<l; i++){
		for(int j=0; j<c; j++){
			for(int k=0; k<n; k++){

				//cout << "coll:" << coll[k] << endl;

				if(j+(int)coll[k].size() <= c){
					for(int s=0; s<(int)coll[k].size(); s++){
						buf[s] = ma[i][j+s];
					}
					sort(buf, buf+(int)coll[k].size());
					buf[coll[k].size()]=0;

					//cout << buf << endl;

					if(buf == coll[k]){

						//cout << i << ' ' << j << ' '  << "OK" << endl;

						for(int s=0; s<(int)coll[k].size(); s++){
							mark[i][j+s] |= (1<<k);
						}
					}
				}
				if(i+(int)coll[k].size() <= l){
					for(int s=0; s<(int)coll[k].size(); s++){
						buf[s] = ma[i+s][j];
					}
					sort(buf, buf+(int)coll[k].size());
					buf[coll[k].size()]=0;
					if(buf == coll[k]){
						for(int s=0; s<(int)coll[k].size(); s++){
							mark[i+s][j] |= (1<<k);
						}
					}
				}
				if(i+(int)coll[k].size() <= l && j+(int)coll[k].size() <= c){
					for(int s=0; s<(int)coll[k].size(); s++){
						buf[s] = ma[i+s][j+s];
					}
					sort(buf, buf+(int)coll[k].size());
					buf[coll[k].size()]=0;
					if(buf == coll[k]){
						for(int s=0; s<(int)coll[k].size(); s++){
							mark[i+s][j+s] |= (1<<k);
						}
					}
				}
				if(i-(int)coll[k].size() >= -1 && j+(int)coll[k].size() <= c){
					for(int s=0; s<(int)coll[k].size(); s++){
						buf[s] = ma[i-s][j+s];
					}
					sort(buf, buf+(int)coll[k].size());
					buf[coll[k].size()]=0;
					if(buf == coll[k]){
						for(int s=0; s<(int)coll[k].size(); s++){
							mark[i-s][j+s] |= (1<<k);
						}
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=0; i<l; i++){
		for(int j=0; j<c; j++){

			//cout << mark[i][j] << ' ';

			if(sig[mark[i][j]]==false){
				ans++;
			}
		}

		//cout << endl;

	}
	cout << ans << endl;
}
