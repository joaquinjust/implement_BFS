#include<bits/stdc++.h>
using namespace std;
int BFS(int sx, int sy, int tx, int ty, int n, int m, vector<string> &s) {
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    vector<vector<int>> D(n, vector<int>(m, -1));
    queue<pair<int, int>> Q;
    D[sx][sy] = 0;
    Q.push({sx, sy});
    while (!Q.empty()) {
        auto [ux, uy] = Q.front();
        Q.pop();
        for (int k = 0; k < 4; ++k) {
            int vx = ux + dx[k], vy = uy + dy[k];
            if (vx < 0 || vy < 0 || vx >= n || vy >= m) continue;
            if (s[vx][vy] == '#' || D[vx][vy] != -1) continue;
            D[vx][vy] = D[ux][uy] + 1;
            Q.push({vx, vy});
        }
    }
    return D[tx][ty];
}
int main() {
    cin.tie(0) -> sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    int sx = 0, sy = 0, tx = n - 1, ty = m - 1;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == 'S') { sx = i; sy = j; }
            if (s[i][j] == 'E') { tx = i; ty = j; }
        }
    }
    cout << BFS(sx, sy, tx, ty, n, m, s) << '\n';
    return 0;
}

/*
5 8
S..#....
.#.#.##.
.#...#..
.####.#.
......#E

 */
