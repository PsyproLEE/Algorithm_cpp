#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);

    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int m;
    cin >> m;
    int x;
    while(m--) {
        cin >> x;
        // lower_bound: x보다 크거나 같은 첫 번째 위치
        // upper_bound: x보다 큰 첫 번째 위치
        int lower = lower_bound(v.begin(), v.end(), x) - v.begin();
        int upper = upper_bound(v.begin(), v.end(), x) - v.begin();
        cout << upper - lower << ' ';
    }

    return 0;
}
