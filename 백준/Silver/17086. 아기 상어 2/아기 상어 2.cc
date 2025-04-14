#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[8] = {1, 0, -1, -1, -1, 0, 1, 1};
vector<vector<int>> map;
vector<pair<int, int>> shark;
vector<vector<bool>> visited;  
int n, m;

int bfs() {
    queue<tuple<int, int, int>> q;
    
    
    for (auto itr : shark) {
        q.push({itr.first, itr.second, 0});
        visited[itr.first][itr.second] = true;  
    }

    int maxdis = 0;
    
    while (!q.empty()) {
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int dis = get<2>(q.front());
        q.pop();
        
        for (int i = 0; i < 8; ++i) {
            int newy = y + dy[i];
            int newx = x + dx[i];
            int newdis = dis + 1;

            if (newy < 0 || newy >= n || newx < 0 || newx >= m) {
                continue;
            }

            if (map[newy][newx] == 0 && !visited[newy][newx]) {
                visited[newy][newx] = true;  
                q.push({newy, newx, newdis});
                maxdis = max(maxdis, newdis); 
            }
        }
    }

    return maxdis;  
}

int main() {
    cin >> n >> m;
    map.resize(n, vector<int>(m, 0));
    visited.resize(n, vector<bool>(m, false)); 


    for (int i = 0; i < n; ++i) { 
        for (int j = 0; j < m; ++j) {  
            cin >> map[i][j];
            if (map[i][j] == 1) {
                shark.push_back({i, j});  
            }
        }
    }

    cout << bfs();
}
