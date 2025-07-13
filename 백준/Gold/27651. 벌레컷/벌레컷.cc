#include <iostream>
using namespace std;
using ll = long long;

ll dp[1000001], sum[1000001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n, ans = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> dp[i];
        sum[i] = sum[i - 1] + dp[i];
    }

    for (int i = 1; i < n - 1; i++) {
        ll h = sum[i];
        ll f = i + 1, e = n - 1;
        ll idx = -1;

        while (f <= e) {
            ll m = (f + e) / 2;
            if (sum[n] - sum[m] > h) {
                idx = m;
                f = m + 1;
            } else {
                e = m - 1;
            }
        }

        if (idx == -1) continue;

        f = i + 1, e = n - 1;
        ll right = -1;

        while (f <= e) {
            ll m = (f + e) / 2;
            if (sum[m] - h > sum[n] - sum[m]) {
                right = m;
                e = m - 1;
            } else {
                f = m + 1;
            }
        }

        if (right != -1 && idx >= right) {
            ans += idx - right + 1;
        }
    }

    cout << ans << '\n';
}
