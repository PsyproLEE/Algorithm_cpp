#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int k, t, n;

    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int min_diff = 1e9, cnt = 0;
        int st = 0, end = n - 1;
        while (st < end)
        {
            int sum = v[st] + v[end];
            int diff = abs(k - sum);
            if (diff < min_diff)
            {
                cnt = 1;
                min_diff = diff;
            }
            else if (diff == min_diff)
            {
                cnt += 1;
            }
            if (sum < k)
                st++;
            else
                end--;
        }
        cout << cnt << '\n';
    }
    return 0;
}