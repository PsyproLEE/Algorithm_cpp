#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> top(n), bottom(n);
    for (int i = 0; i < n; ++i) cin >> top[i];
    for (int i = 0; i < n; ++i) cin >> bottom[i];

    vector<int> gap(n);
    for (int i = 0; i < n; ++i)
        gap[i] = top[i] - bottom[i];

    for (int i = 1; i < n; ++i)
        gap[i] = min(gap[i], gap[i - 1]);

    int q;
    cin >> q;

    vector<pair<int, int>> birds(q);
    for (int i = 0; i < q; ++i) {
        int w;
        cin >> w;
        birds[i] = {w, i}; 
    }

  
    sort(birds.begin(), birds.end(), greater<>());

    vector<int> ans(q);
    int r = 0; // 현재 통과 가능한 장애물 인덱스

    for (auto &[w, idx] : birds) {
        while (r < n && gap[r] >= w)
            ++r;
        ans[idx] = r;
    }

    for (int i = 0; i < q; ++i)
        cout << ans[i] << '\n';

    return 0;
}
