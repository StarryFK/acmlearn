#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
 
using namespace std;
 
const int MAXN = 1e5 + 1;
 
struct node
{
	int ed, num;
	
	node();
	
	node(int ed_, int num_) : ed(ed_) , num(num_)
	{
		
	}
	
	bool operator < (const node& n)
	{
		return num < n.num;
	}
};
 
vector<node> a[MAXN];
int tong[MAXN];
	int di[MAXN];
	
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n - 1; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[x].push_back(node(y, z));
		a[y].push_back(node(x, z));
	}
	for (int i = 1; i <= n; i++)
	sort(a[i].begin(), a[i].end());
	
	int ans = k;
	memset(tong, 0, sizeof(tong));
	
	
	for (int i = 1; i <= k; i++)
	{
		scanf("%d", &di[i]);
		tong[di[i]] = 1;
	}
	
	for (int i = 1; i <= k; i++)
	{
		int now = di[i];
		int num = (*a[now].begin()).num, ed = (*a[now].begin()).ed;
		int bj = 0;
		for (vector<node>::iterator it = a[now].begin(); it != a[now].end(); ++it)
		if ((*it).num == num && (*it).ed != ed)
		{
			bj = 1;
		}
		if (bj == 0)
		{
			if (tong[ed] == 0)
			{
				ans++;
				tong[ed] = 1;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
/*
4 1
1 2 1
1 3 1
1 4 1
1
*/
