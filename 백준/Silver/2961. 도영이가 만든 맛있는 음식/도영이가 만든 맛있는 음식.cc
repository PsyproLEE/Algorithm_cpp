#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<long long> S(N), B(N);
    for (int i = 0; i < N; ++i) cin >> S[i] >> B[i];

    long long ans = 2e9;
    for (int mask = 1; mask < (1 << N); ++mask) { // 공집합 제외 1..(2^N-1)
        long long prodS = 1, sumB = 0;
        for (int i = 0; i < N; ++i) {
            if (mask & (1 << i)) {
                prodS *= S[i];
                sumB += B[i];
            }
        }
        ans = min(ans, llabs(prodS - sumB));
    }
    cout << ans << "\n";
}