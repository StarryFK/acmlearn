#include <cstring>
#include <iostream>
using namespace std;

const int MAXN = 1e5 + 5;

int father[MAXN];
int id[MAXN];
int idcnt[MAXN];
int ids = 1;

int find(int f){
    if(id[f]!=f){
        return find(id[f]);
    }
    return f;
}

void uni(int u, int v) {
    if (father[u] == 0 && father[v] == 0) {
        father[u] = ids;
        father[v] = ids;
        idcnt[ids] += 2;
        ids++;
    } else if (father[u] == 0) {
        father[u] = father[v];
        idcnt[father[v]]++;
    } else if (father[v] == 0) {
        father[v] = father[u];
        idcnt[father[u]]++;
    } else {
        id[find(father[u])] = find(father[v]);
    }
}

void change(int u, int v) {
    idcnt[father[u]]--;
    father[u] = 0;
    uni(u, v);
}

bool check(int u, int v) { return find(father[u]) == find(father[v]); }

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    memset(father, 0, sizeof(father));
    memset(idcnt, 0, sizeof(idcnt));
    for (int i = 0; i < MAXN; i++) {
        id[i] = i;
    }
    int op, u, v;
    for (int i = 0; i < m; i++) {
        cin >> op >> u >> v;
        if (op == 1) {
            uni(u, v);
        } else if (op == 2) {
            change(u, v);
        } else if (op == 3) {
            cout << (check(u, v) ? "YES" : "NO") << endl;
        }
    }
    int result = 0;
    for (int i = 1; i < ids; i++) {
        
      //  cout << idcnt[i] << endl;
  //      cout << "id:" << id[i] << endl;

        if (idcnt[i] != 0 && id[i] == i) {
            result++;
        }
    }
    //    cout << "--"<<endl;
    for (int i = 1; i <= n; i++) {
        if (father[i] == 0) {
            result++;
        }
    }

    cout << result << endl;
}