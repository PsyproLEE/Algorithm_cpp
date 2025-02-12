#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> vec;  
vector<bool> visited; 
int n, m, v;


void dfs(int node) {
    
    cout << node << " ";  
    visited[node] = true;

    for (int i = 1; i <= n; ++i) {
        if (vec[node][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

void bfs(int start) {
    queue<int> q;
    vector<bool> visited_bfs(n + 1, false); 

    q.push(start);
    visited_bfs[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 1; i <= n; ++i) {
            if (vec[node][i] == 1 && !visited_bfs[i]) {
                visited_bfs[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> v;
    
    vec.resize(n + 1, vector<int>(n + 1, 0));
    visited.resize(n + 1, false);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        vec[a][b] = vec[b][a] = 1;
    }

    dfs(v);
    cout << '\n';
    
    bfs(v);
    cout << '\n';

    return 0;
}
