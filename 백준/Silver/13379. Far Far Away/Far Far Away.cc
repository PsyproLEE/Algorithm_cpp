#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, c, m;
vector<vector<pair<int, int>>> graph;
int maxDist;

void dfs(int curr, int dist) {
    maxDist = max(maxDist, dist);

    for (auto &next : graph[curr]) {
        dfs(next.first, dist + next.second);
    }
}

int main() {
    cin >> t;
    while (t--) {
        cin >> c >> m;

        graph.assign(c + 1, vector<pair<int, int>>());
        maxDist = -1;

        for (int i = 0; i < c - 1; ++i) {
            int u, v, d;
            cin >> u >> v >> d;
            graph[u].push_back({v, d});
        }

        dfs(1, 0);

        if (maxDist >= m) cout << maxDist << '\n';
        else cout << -1 << '\n';
    }
}
