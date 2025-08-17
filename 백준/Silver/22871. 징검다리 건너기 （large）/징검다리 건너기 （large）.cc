#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1LL<<62);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N; cin >> N;
    vector<ll> A(N+1);
    for (int i = 1; i <= N; ++i) cin >> A[i];

    
    vector<ll> dp(N+1, INF);
    dp[1] = 0;

    for (int j = 2; j <= N; ++j) {
        long long best = INF;
        for (int i = 1; i < j; ++i) {
            long long cost = 1LL * (j - i) * (1 + llabs(A[i] - A[j]));
            long long val = max(dp[i], cost);
            if (val < best) best = val;
        }
        dp[j] = best;
    }

    cout << dp[N] << "\n";
    return 0;
}
