#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    long long t, n, m, k;
    cin >> t;
    while(t--){

        cin >> n >> m >> k;
        vector<long long> v(n);

        for (int i = 0; i<n; ++i){
            cin >> v[i];
        }
        if (m == n) {
            long long sum = 0;
            for (int i = 0; i < n; ++i)
                sum += v[i];
            cout << (sum < k ? 1 : 0) << '\n';
            continue;
        }
        long long sum =0 , cnt = 0;

        for (int i = 0; i < m; ++i)
            sum += v[i];
        if (sum < k) cnt++;


        for (int i = 1; i < n; ++i) {
            sum -= v[(i - 1) % n];
            sum += v[(i + m - 1) % n];

            if (sum < k)
                cnt++;
        }
        cout << cnt << '\n';

    }

    return 0;
}