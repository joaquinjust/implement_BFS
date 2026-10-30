#include<bits/stdc++.h>
using namespace std;
vector<int> BFS(vector<int> &fuentes, int n, vector<vector<int>> &G, vector<int> &padre) {
    vector<int> dist(n, -1);
    padre.assign(n, -1);
    queue<int> Q;
    for (int s : fuentes) {
        dist[s] = 0;
        Q.push(s);
    }
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int v : G[u]) {
            if (dist[v] != -1) continue;
            dist[v] = dist[u] + 1;
            padre[v] = u;
            Q.push(v);
        }
    }
    return dist;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> fuentes = {0};
    vector<int> padre;
    vector<int> dist = BFS(fuentes, n, G, padre);
    for (int i = 0; i < n; ++i) cout << dist[i] << " \n"[i + 1 == n];
    return 0;
}

/*
5 4
1 2
2 3
3 4
1 5
*/
