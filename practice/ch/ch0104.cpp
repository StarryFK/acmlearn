#include <iostream>
#include <string>
using namespace std;
const int MAXN = 1e5 + 7;

int op[MAXN];
int t[MAXN];
int n, m;

int result(int in, int bit) {
	int ans = in << bit;
	for (int i = 0; i < n; i++) {
		if (op[i] == 1) {
			ans = ans & t[i];
		} else if (op[i] == 2) {
			ans = ans | t[i];
		} else {
			ans = ans ^ t[i];
		}
	}
	return (ans >> bit) & 1;
}

int main() {
	cin >> n >> m;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "AND") {
			op[i] = 1;
		} else if (s == "OR") {
			op[i] = 2;
		} else {
			op[i] = 3;
		}
		cin >> t[i];
	}
	int in = 0;
	int out = 0;
	for (int i = 29; i >= 0; i--) {
		int res0 = result(0, i);
		int res1 = result(1, i);
		if (res0 < res1 && in + (1 << i) <= m) {
			in += 1 << i;
			out += res1 << i;
		} else {
			out += res0;
		}
        //cout << out << endl;
	}
	cout << out << endl;
}