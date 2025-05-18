#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
#define MAX 100
using namespace std;

vector<int> mdistance;
vector<bool> visited;
int V, e, start;
typedef pair<int, int> edge;
vector<vector<edge>> mlist;
priority_queue<edge, vector<edge>, greater<edge>> pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> e >> start;
    mdistance.resize(V + 1, INT_MAX);
    visited.resize(V + 1, false);
    mlist.resize(V + 1);

    for (int i = 0; i < e; ++i) {
        int u, v, m;
        cin >> u >> v >> m;
        mlist[u].push_back(make_pair(v, m));
    }

    pq.push(make_pair(0, start));
    mdistance[start] = 0;

    while (!pq.empty()) {
        edge current = pq.top();
        pq.pop();
        int cv = current.second;

        if (visited[cv]) continue;
        visited[cv] = true;

        for (edge temp : mlist[cv]) {
            int next = temp.first;
            int value = temp.second;

            if (mdistance[next] > mdistance[cv] + value) {
                mdistance[next] = mdistance[cv] + value;
                pq.push(make_pair(mdistance[next], next));
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (mdistance[i] == INT_MAX) cout << "INF\n";
        else cout << mdistance[i] << "\n";
    }

    return 0;
}
