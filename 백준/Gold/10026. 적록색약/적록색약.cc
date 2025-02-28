#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n;
vector<string> map;
vector<vector<bool>> visited;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    map.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> map[i];
    }
}

void dfs(int y, int x, char color) {
    stack<pair<int, int>> s;
    s.push({y, x});
    visited[y][x] = true;

    while (!s.empty()) {
        auto [cy, cx] = s.top();
        s.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            // 범위 검사 및 방문 확인
            if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
                if (!visited[ny][nx] && map[ny][nx] == color) {
                    visited[ny][nx] = true;
                    s.push({ny, nx});
                }
            }
        }
    }
}

// 영역 개수 세기
int countRegions() {
    visited.assign(n, vector<bool>(n, false));
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                count++;
                dfs(i, j, map[i][j]);
            }
        }
    }
    return count;
}

int main() {
    input();

    int normalCount = countRegions();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 'R') map[i][j] = 'G';
        }
    }

    int colorblindCount = countRegions();

    cout << normalCount << " " << colorblindCount << endl;
}
