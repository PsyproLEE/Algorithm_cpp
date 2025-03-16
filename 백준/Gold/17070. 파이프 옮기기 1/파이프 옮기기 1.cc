#include <iostream>

using namespace std;

int n;
int map[17][17];
long long dp[17][17][3]; 
// dir: 0 = 가로, 1 = 세로, 2 = 대각선

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    fill(&map[0][0], &map[0][0] + 17 * 17, 1);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> map[i][j];
        }
    }

    dp[1][2][0] = 1;

    // DP 테이블 채우기
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (map[i][j] == 1) continue; // 벽이 있으면 이동 불가

            // 1) 가로(→) 이동
            if (j - 1 >= 1) dp[i][j][0] += dp[i][j - 1][0] + dp[i][j - 1][2];

            // 2) 세로(↓) 이동
            if (i - 1 >= 1) dp[i][j][1] += dp[i - 1][j][1] + dp[i - 1][j][2];

            // 3) 대각선(↘) 이동 (세 칸이 모두 비어있어야 가능)
            if (i - 1 >= 1 && j - 1 >= 1 && map[i - 1][j] == 0 && map[i][j - 1] == 0)
                dp[i][j][2] += dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
        }
    }

    cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
}
