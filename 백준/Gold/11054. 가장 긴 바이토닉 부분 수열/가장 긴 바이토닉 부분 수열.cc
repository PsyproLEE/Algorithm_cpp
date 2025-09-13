#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    vector<int> increase(n, 1);
    vector<int> decrease(n, 1); 

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (v[i] > v[j]) {
                increase[i] = max(increase[i], increase[j] + 1);
            }
        }
    }
  
    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j > i; --j) {
            if (v[i] > v[j]) {
                decrease[i] = max(decrease[i], decrease[j] + 1);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, increase[i] + decrease[i] - 1);
    }

    cout << ans << '\n';
    return 0;
}