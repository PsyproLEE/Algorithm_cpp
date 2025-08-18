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
    vector<int> past(1000001, 0);

    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        int a, b, c; cin >> a>> b>> c;

        bool is_seen = (past[a] || past[b] || past[c]);
        if(!is_seen) cnt++;

        past[a] = past[b] = past[c] = 1;
    }
    cout << cnt ;
    return 0;
}
