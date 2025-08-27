#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<int> ans(m);
    vector<vector<int>> model(n, vector<int>(m));

    for (int i = 0; i < m; ++i)
        cin >> ans[i];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> model[i][j];
        }
    }

    int bestSingle = 0;
    for (int i = 0; i < n; ++i)
    {
        int corr = 0;
        for (int j = 0; j < m; ++j)
            if (model[i][j] == ans[j])
                ++corr;
        bestSingle = max(bestSingle, corr);
    }

    int mcnt = 0;
    vector<unsigned int> oneMask(m, 0);
    for (int j = 0; j < m; ++j)
    {
        unsigned int bm = 0;
        for (int i = 0; i < n; ++i)
            if (model[i][j] == 1)
                bm |= (1u << i);
        oneMask[j] = bm;
    }

    for (int mask = 1; mask < (1 << n); ++mask)
    {
        int k = __builtin_popcount((unsigned)mask);
        if (k < 3 || (k % 2 == 0))
            continue; // 홀수이면서 3 이상만

        int corr = 0;
        int half = k / 2;
        for (int j = 0; j < m; ++j)
        {
            int ones = __builtin_popcount((unsigned)(mask & oneMask[j]));
            int pred = (ones > half) ? 1 : 0;
            if (pred == ans[j])
                ++corr;
        }
        if (corr > bestSingle)
        {
            cout << 1 << "\n";
            return 0;
        }
    }
    cout << 0 << "\n";
    return 0;
}