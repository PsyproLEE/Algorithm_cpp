#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Node {
    int x, y, v;
    bool p;
};

int N, K, T;
vector<Node> nodes;
vector<int> parent;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
    int ra = find(a);
    int rb = find(b);
    if (ra != rb) parent[rb] = ra;
}

int dist2(int i, int j) {
    int dx = nodes[i].x - nodes[j].x;
    int dy = nodes[i].y - nodes[j].y;
    return dx * dx + dy * dy;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K >> T;
    nodes.resize(N + 1);
    parent.resize(N + 1);

    cin >> nodes[0].x >> nodes[0].y >> nodes[0].v;
    nodes[0].p = false;
    parent[0] = 0;

    for (int i = 1; i <= N; ++i) {
        cin >> nodes[i].x >> nodes[i].y >> nodes[i].v >> nodes[i].p;
        parent[i] = i;
    }

    int K2 = K * K;

    for (int i = 0; i <= N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            if (abs(nodes[i].v - nodes[j].v) <= T && dist2(i, j) <= K2) {
                merge(i, j);
            }
        }
    }

    int puangRoot = find(0);
    vector<int> result;

    for (int i = 1; i <= N; ++i) {
        if (nodes[i].p && find(i) == puangRoot) {
            result.push_back(i);
        }
    }

    if (result.empty()) cout << 0 << '\n';
    else {
        sort(result.begin(), result.end());
        for (int i : result) cout << i << ' ';
        cout << '\n';
    }

    return 0;
}
