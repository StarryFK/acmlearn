#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;

string d1,d2;

const int monday[2][13] = {{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};

bool leap(int year){
	if(year%4==0){
		if(year%100==0){
			if(year%400==0){
				return true;
			}else{
				return false;
			}
		}else{
			return true;
		}
	}else{
		return false;
	}
}

int main(){
	ios::sync_with_stdio(false);
	while(cin >> d1 >> d2){
		int xq=0;
		int cnt[8];
		memset(cnt, 0, sizeof(cnt));
		cin >> xq;
		int year, month, day, eyear, emonth, eday;
		year = stoi(d1.substr(0, 4));
		month = stoi(d1.substr(5, 2));
		day = stoi(d1.substr(8, 2));
		eyear = stoi(d2.substr(0, 4));
		emonth = stoi(d2.substr(5, 2));
		eday = stoi(d2.substr(8, 2));
		while(!(year==eyear && month==emonth && day==eday)){

			//cout << year << month << day << xq << endl;

			if(((month==1 && day>29) || (month==2 && day<11)) || ((month==7 && day>11) || (month==8 && day<23))){
				goto nextday;
			}
			if(((month==2 && day==14)||(month==8 && day==25))){
				cnt[1]++;
				goto nextday;
			}
			if(day==1){
				cnt[3]++;
				goto nextday;
			}
			if(day==monday[leap(year)][month]){
				cnt[4]++;
				goto nextday;
			}
			cnt[xq]++;
nextday:
			day++;
			if(day>monday[leap(year)][month]){
				day=1;
				month++;
			}
			if(month>12){
				month=1;
				year++;
			}
			xq++;
			if(xq>7){
				xq=1;
			}
		}
		if(((month==1 && day>29) || (month==2 && day<11)) || ((month==7 && day>11) || (month==8 && day<23))){
			goto next;
		}
		if(((month==2 && day==14)||(month==8 && day==25))){
			cnt[1]++;
			goto next;
		}
		if(day==1){
			cnt[3]++;
			goto next;
		}
		if(day==monday[leap(year)][month]){
			cnt[4]++;
			goto next;
		}
		cnt[xq]++;
next:
		for(int i=1; i<=7; i++){
			cout << cnt[i] << endl;
		}
	}
}
