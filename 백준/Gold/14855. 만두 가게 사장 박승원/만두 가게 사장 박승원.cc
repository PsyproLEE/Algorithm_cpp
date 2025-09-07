#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, c0, d0;             
    cin >> N >> M >> c0 >> d0;

    vector<int> dp(N + 1, 0);

    for (int i = 0; i < M; ++i) {
        int a, b, c, d;             
        cin >> a >> b >> c >> d;

        int cnt = a / b;             
        if (cnt == 0 || c > N) continue;
        cnt = min(cnt, N / c);        

        for (int k = 1; cnt > 0; k <<= 1) {
            int take = min(k, cnt);
            int W = c * take, V = d * take;
            for (int w = N; w >= W; --w)           
                dp[w] = max(dp[w], dp[w - W] + V);
            cnt -= take;
        }
    }

    if (c0 <= N) {
        for (int w = c0; w <= N; ++w)
            dp[w] = max(dp[w], dp[w - c0] + d0);
    }

    cout << dp[N] << '\n';
    return 0;
}
