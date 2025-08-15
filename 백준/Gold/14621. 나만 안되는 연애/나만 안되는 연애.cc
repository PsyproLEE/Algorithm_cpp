#include <bits/stdc++.h>
using namespace std;

using ll  = long long;
using PII = pair<int,int>; // (cost, vertex)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; 
    cin >> n >> m;

    vector<char> sex(n+1);
    for (int i = 1; i <= n; ++i) cin >> sex[i];

    vector<vector<PII>> g(n+1); // g[u] = {(v, w)}
    for (int i = 0; i < m; ++i) {
        int u, v, w; 
        cin >> u >> v >> w;
        g[u].push_back(PII(v, w));
        g[v].push_back(PII(u, w));
    }

    vector<int> visited(n+1, 0);
    priority_queue<PII, vector<PII>, greater<PII>> pq;

    // start from 1
    pq.push(PII(0, 1));
    ll total = 0;
    int picked = 0;

    while (!pq.empty()) {
        PII top = pq.top(); pq.pop();
        int cw = top.first;
        int u  = top.second;
        if (visited[u]) continue;
        visited[u] = 1;
        total += cw;
        ++picked;

        // push only edges to different-gender vertices
        for (const PII &e : g[u]) {
            int v = e.first;
            int w = e.second;
            if (!visited[v] && sex[u] != sex[v]) {
                pq.push(PII(w, v));
            }
        }
    }

    cout << (picked == n ? total : -1) << '\n';
    return 0;
}
