#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
struct item{ int value, weight;};
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<item> itemv(n + 1, item());

    for (int i = 1; i <= n; ++i)
    {
        cin >> itemv[i].weight >> itemv[i].value;
    }

    vector<int> bags(m + 1);
    int Wmax = 0;
    for (int i = 1; i <= m; ++i)
    {
        cin >> bags[i];
        Wmax = max(Wmax, bags[i]);
    }

    vector<int> dp(Wmax + 1, 0);

    for (int i = 1; i <= n; ++i) {
        int wt = itemv[i].weight;
        int val = itemv[i].value;
        for (int w = Wmax; w >= wt; --w) {
            dp[w] = max(dp[w], dp[w - wt] + val);
        }
    }
    int best_idx = 1;
    for (int i = 2; i <= m; ++i) {
        int w1 = bags[best_idx], w2 = bags[i];
        long long lhs = (w1 == 0 ? -1LL : 1LL * dp[w1] * w2);
        long long rhs = (w2 == 0 ? -1LL : 1LL * dp[w2] * w1);
        if (rhs > lhs) best_idx = i;
    }
    cout << best_idx;
    return 0;
}