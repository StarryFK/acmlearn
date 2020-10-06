#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

bool edge[5005][5005];
int nodein[5005];
int depth[5005];
int layer[5005];
queue<int> q;
int a, b, e, p;

void dfs(int father, int dep) {
	depth[father] = dep;
	for (int i = 0; i < e; i++) {
		if (edge[father][i] && depth[i] > dep + 1) {
			dfs(i, dep + 1);
		}
	}
}

int main() {
	memset(edge, 0, sizeof(edge));
	memset(nodein, 0, sizeof(nodein));
	memset(depth, 0x3F, sizeof(depth));
	cin >> a >> b >> e >> p;
	for (int i = 0; i < p; i++) {
		int from, to;
		cin >> from >> to;
		nodein[to]++;
		edge[from][to] = true;
	}
	for (int i = 0; i < e; i++) {
		if (!nodein[i]) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		dfs(q.front(), 0);
		q.pop();
	}
	for (int i = 0; i < e; i++) {
		layer[depth[i]]++;
	}
	int tot = 0;
	int ans1 = 0, ans2 = 0, ans3 = 0;
	for (int i = 0; i < 10; i++) {
		cout << layer[i] << endl;
	}
	for (int i = 0; i < e; i++) {
		tot += layer[i];
		if (tot == a && !ans1) {
			ans1 = tot;
		}
		if (tot > a && !ans1) {
			ans1 = tot - layer[i];
		}
		if (tot == b && !ans2) {
			ans2 = tot;
			ans3 = e - tot;
		}
		if (tot > b && !ans2) {
			ans2 = tot - layer[i];
			ans3 = e - tot;
		}
	}
	cout << ans1 << endl << ans2 << endl << ans3 << endl;
}