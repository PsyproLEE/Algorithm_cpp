#include <iostream>
#include <vector>
using namespace std;

int R, C;
vector<vector<char>> pasture;
vector<vector<bool>> visited;
int dx[] = {1, -1, 0, 0}; // 상하좌우 이동
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < R && ny >= 0 && ny < C && !visited[nx][ny] && pasture[nx][ny] == '#') {
            dfs(nx, ny);
        }
    }
}

int countGrassClumps() {
    int count = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (!visited[i][j] && pasture[i][j] == '#') {
                count++;
                dfs(i, j);
            }
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;
    pasture.resize(R, vector<char>(C));
    visited.resize(R, vector<bool>(C, false));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> pasture[i][j];
        }
    }

    cout << countGrassClumps() << '\n';
    return 0;
}
