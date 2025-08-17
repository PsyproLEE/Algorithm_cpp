#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

using namespace std;
using ll = long long;
const ll INF = numeric_limits<ll>::max() / 4;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<int> watch(N);
    for (int i = 0; i < N; ++i) cin >> watch[i];
    watch[N - 1] = 0; // 목적지는 항상 진입 허용

    vector<vector<pair<int, ll>>> g(N);
    for (int i = 0; i < M; ++i) {
        int u, v; ll w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    // 시작점이 감시 중이면 불가능
    if (watch[0]) {
        cout << -1 << '\n';
        return 0;
    }

    vector<ll> dist(N, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    dist[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        pair<ll,int> cur = pq.top(); pq.pop();
        ll cd = cur.first;
        int u = cur.second;
        if (cd != dist[u]) continue;

        for (size_t i = 0; i < g[u].size(); ++i) {
            int v = g[u][i].first;
            ll w = g[u][i].second;
            if (watch[v] && v != N - 1) continue; // 감시 중이면 이동 불가

            ll nd = cd + w;
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push({nd, v});
            }
        }
    }

    cout << (dist[N - 1] >= INF ? -1 : dist[N - 1]) << '\n';
    return 0;
}
