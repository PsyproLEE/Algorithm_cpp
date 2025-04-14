#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, k;
vector<vector<int>> people;

int bfs(int start) {
    vector<bool> visited(n + 1, false);
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = true;
    int max_depth = 0;

    while (!q.empty()) {
        int cur = q.front().first;
        int depth = q.front().second;
        q.pop();

        for (int next : people[cur]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push({next, depth + 1});
                max_depth = max(max_depth, depth + 1);
            }
        }
    }


    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) return 1e9;
    }

    return max_depth;
}

int main() {
    cin >> n >> k;
    people.resize(n + 1);

    int a, b;
    while (k--) {
        cin >> a >> b;
        people[a].push_back(b);
        people[b].push_back(a);
    }

    bool isSmallWorld = true;
    for (int i = 1; i <= n; ++i) {
        int max_dist = bfs(i);
        if (max_dist > 6) {
            isSmallWorld = false;
            break;
        }
    }

    if (isSmallWorld)
        cout << "Small World!";
    else
        cout << "Big World!";
}
