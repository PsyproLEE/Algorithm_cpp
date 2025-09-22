#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
const ll MOD = 1000000007;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m));
    vector<vector<ll>> dp(n, vector<ll>(m, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> v[i][j];
        }
    }

    for (int j = 0; j < m; ++j) {
        if (v[0][j] == 1) {
            dp[0][j] = 1;
        }
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (v[i][j] == 1) { 

                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                
                if (j > 0) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                }
                
                if (j < m - 1) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
                }
            }
        }
    }

   
    ll total_paths = 0;
    for (int j = 0; j < m; ++j) {
        total_paths = (total_paths + dp[n - 1][j]) % MOD;
    }

    cout << total_paths;

    return 0;
}