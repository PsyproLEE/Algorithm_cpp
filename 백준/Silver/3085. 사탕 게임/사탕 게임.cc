#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<char>> board;

int getMaxCandy() {
    int maxCnt = 1;

    for (int i = 0; i < n; i++) {
        int rowCnt = 1, colCnt = 1;

        for (int j = 1; j < n; j++) {
            // 가로 방향 검사
            if (board[i][j] == board[i][j - 1])
                rowCnt++;
            else
                rowCnt = 1;

            // 세로 방향 검사
            if (board[j][i] == board[j - 1][i])
                colCnt++;
            else
                colCnt = 1;

            maxCnt = max({maxCnt, rowCnt, colCnt});
        }
    }
    return maxCnt;
}

void swapAndCheck(int x1, int y1, int x2, int y2, int &maxCandy) {
    swap(board[x1][y1], board[x2][y2]);
    maxCandy = max(maxCandy, getMaxCandy());
    swap(board[x1][y1], board[x2][y2]); // 원래대로 복구
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    board.resize(n, vector<char>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    int maxCandy = getMaxCandy();

    // 모든 칸에서 인접한 것과 교환
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j + 1 < n) swapAndCheck(i, j, i, j + 1, maxCandy); // 오른쪽과 교환
            if (i + 1 < n) swapAndCheck(i, j, i + 1, j, maxCandy); // 아래쪽과 교환
        }
    }

    cout << maxCandy;
}
