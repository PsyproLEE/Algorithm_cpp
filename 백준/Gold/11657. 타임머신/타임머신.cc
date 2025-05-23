#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

const long long INF = 1e18;

int main() {
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> edges;

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(make_tuple(u, v, w));
    }

    vector<long long> dist(n + 1, INF);
    dist[1] = 0;

    // N-1번 반복
    for (int i = 1; i < n; ++i) {
        for (size_t j = 0; j < edges.size(); ++j) {
            int u = get<0>(edges[j]);
            int v = get<1>(edges[j]);
            int w = get<2>(edges[j]);

            if (dist[u] != INF && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // 음의 사이클 존재 여부 확인
    bool negative = false;
    for (size_t j = 0; j < edges.size(); ++j) {
        int u = get<0>(edges[j]);
        int v = get<1>(edges[j]);
        int w = get<2>(edges[j]);

        if (dist[u] != INF && dist[v] > dist[u] + w) {
            negative = true;
            break;
        }
    }

    if (negative) {
        cout << -1 << '\n';
    } else {
        for (int i = 2; i <= n; ++i) {
            if (dist[i] == INF)
                cout << -1 << '\n';
            else
                cout << dist[i] << '\n';
        }
    }

    return 0;
}
