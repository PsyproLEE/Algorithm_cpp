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

    vector<int> v(n, 0);

    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    int start = 0, end = n - 1;
    int cnt = 0;

    
    while (start < end)
    {
        if (v[start] + v[end] >= m)
        {
            start++;
            end--;
            cnt++;
        }

        else 
            start++;

    }

    cout << cnt;
    return 0;
}