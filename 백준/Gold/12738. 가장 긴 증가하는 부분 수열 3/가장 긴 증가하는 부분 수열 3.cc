#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> tmp;
    tmp.push_back(arr[0]);

    for (int i = 1; i < n; ++i) {
        if (arr[i] > tmp.back()) {
            tmp.push_back(arr[i]);
        } else {
            *lower_bound(tmp.begin(), tmp.end(), arr[i]) = arr[i];
        }
    }

    cout << tmp.size() << '\n';

    return 0;
}