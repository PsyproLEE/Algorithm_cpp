#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    sort(A.begin(), A.end());

    vector<ll> diff;
    diff.reserve(N - 1);
    for (int i = 0; i + 1 < N; ++i) diff.push_back(A[i + 1] - A[i]);

    ll total = 0;
    for (ll d : diff) total += d;

    sort(diff.begin(), diff.end(), greater<ll>());
    for (int i = 0; i < K - 1 && i < (int)diff.size(); ++i) total -= diff[i];

    cout << total << '\n';
    return 0;
}
