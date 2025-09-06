#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
const int MOD = 1'000'000'007;
int n;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    vector<ll> weights;
    weights.reserve(n);

    for(int i = 0; i< n; ++i){
        ll a,m;
        cin >> a>> m;
        ll w = (a*m) / 625;
        weights.push_back(w);
    }
    int c1, c2;
    cin >>  c1 >> c2;

    vector<int> items;
    items.reserve(n);

    for (ll w : weights) if (w <= c2) items.push_back((int)w);

    if (items.empty()) {
        cout << 0 << '\n';
        return 0;
    }

    vector<int> dp(c2 + 1, 0);
    dp[0] = 1;

    for (int w : items) {
        for (int s = c2; s >= w; --s) {
            dp[s] += dp[s - w];
            if (dp[s] >= MOD) dp[s] -= MOD;
        }
    }

    long long ans = 0;
    for (int s = c1; s <= c2; ++s) {
        ans += dp[s];
        if (ans >= MOD) ans -= MOD;
    }
    cout << ans << '\n';
    return 0;
}