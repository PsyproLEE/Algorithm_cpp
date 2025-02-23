#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<char>> grid;
vector<vector<bool>> visited;

void markRectangle(int x, int y) {
    int row = x, col = y;

    // 오른쪽으로 끝 찾기
    while (col < M && grid[x][col] == '*') col++;
    col--;

    // 아래쪽으로 끝 찾기
    while (row < N && grid[row][y] == '*') row++;
    row--;

    // 방문 처리
    for (int i = x; i <= row; i++) {
        for (int j = y; j <= col; j++) {
            visited[i][j] = true;
        }
    }
}

int countRectangles() {
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == '*' && !visited[i][j]) {
                count++;
                markRectangle(i, j);
            }
        }
    }
    return count;
}

int main() {
    cin >> N >> M;
    grid.assign(N, vector<char>(M));
    visited.assign(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    cout << countRectangles() << endl;
    return 0;
}
