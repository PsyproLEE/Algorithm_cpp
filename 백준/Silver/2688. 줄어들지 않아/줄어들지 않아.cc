#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<ll>> dp(65, vector<ll>(10, 0));

        for(int i = 0; i < 10; ++i) dp[1][i] = 1;

        for(int i = 2; i <= 64; ++i){
            for(int j = 0; j < 10; ++j){
                for(int k = 0; k <= j; ++k){
                    dp[i][j] += dp[i-1][k];
                }
            }
        }

    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        ll ans = 0;
        for (int i = 0; i <= 9; i++)
			ans += dp[n][i];
        cout << ans << '\n';
    }

    return 0;
}
