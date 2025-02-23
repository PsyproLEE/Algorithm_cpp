#include <iostream>
#include <vector>

using namespace std;

int m, n;
vector<vector<char>> grid;
vector<vector<bool>> visited;

// 8방향 탐색 (상하좌우 + 대각선)
int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

// DFS 탐색 함수
void dfs(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
            if (grid[nx][ny] == '#' && !visited[nx][ny]) {
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    cin >> m >> n;
    grid.resize(m, vector<char>(n));
    visited.resize(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int loop_count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '#' && !visited[i][j]) {
                dfs(i, j);  // 새로운 루프 탐색 시작
                loop_count++;
            }
        }
    }

    cout << loop_count << '\n';
    return 0;
}
