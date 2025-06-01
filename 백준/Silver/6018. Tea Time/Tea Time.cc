#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

int find(int x) {
    if (parent[x] != x) return parent[x] = find(parent[x]);
    return x;
}

void unite(int a, int b) {
    int ra = find(a);
    int rb = find(b);
    if (ra != rb) parent[rb] = ra;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, Q;
    cin >> N >> M >> Q;

    parent.resize(N + 1);
    for (int i = 1; i <= N; i++) parent[i] = i;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        unite(a, b);
    }

    for (int i = 0; i < Q; i++) {
        int x, y;
        cin >> x >> y;
        if (find(x) == find(y)) {
            cout << "Y\n";
        } else {
            cout << "N\n";
        }
    }

    return 0;
}
