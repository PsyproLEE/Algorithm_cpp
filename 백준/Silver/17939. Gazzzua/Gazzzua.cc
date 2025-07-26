#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> price(n);
    for (int i = 0; i < n; ++i)
        cin >> price[i];

    long long ans = 0;
    int max_price = 0;

    for (int i = n - 1; i >= 0; --i) {
        if (price[i] < max_price) {
            ans += (max_price - price[i]);
        } else {
            max_price = price[i];
        }
    }

    cout << ans << '\n';
}