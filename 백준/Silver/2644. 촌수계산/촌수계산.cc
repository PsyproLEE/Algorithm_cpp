#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> family;
vector<bool> visited;
int n, a, b, m, x, y;

int dfs(int start, int finish) {
    stack<pair<int, int>> s; 
    s.push({start, 0});
    visited[start] = true;

    while (!s.empty()) {
        int current = s.top().first;
        int depth = s.top().second;
        s.pop();

        if (current == finish) return depth;

        for (int neighbor : family[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                s.push({neighbor, depth + 1});
            }
        }
    }
    return -1; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> a >> b >> m;
    
    family.resize(n + 1);
    visited.resize(n + 1, false);

    while (m--) {
        cin >> x >> y;
        family[x].push_back(y);
        family[y].push_back(x);
    }

    cout << dfs(a, b);
}
