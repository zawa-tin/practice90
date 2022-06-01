// 003
#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> G;
vector<int> dist;

void search(int v, int p) {
    dist[v] = ++p;
    for (auto& x : G[v]) if (dist[x] == -1) search(x, p);
}

pair<int, int> dfs(int s) {
    dist = vector<int>(n, -1);
    search(s, -1);
    pair<int, int> res = {-1, -1};
    for (int i = 0 ; i < n ; i++) if (dist[i] > res.second) res = make_pair(i, dist[i]);
    return res;
}

int main() {
    cin >> n;
    G = vector<vector<int>>(n);
    for (int i = 0 ; i < n - 1 ; i++) {
        int a, b; cin >> a >> b;
        G[a - 1].push_back(b - 1);
        G[b - 1].push_back(a - 1);
    }

    pair<int, int> maxi = dfs(0);
    cout << dfs(maxi.first).second + 1 << endl;
}
