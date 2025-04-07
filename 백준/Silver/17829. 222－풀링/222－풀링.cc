#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<vector<int>> original;
vector<vector<int>> v;

int tmparr[4] = {};
int arrx[4] = {0, 1, 0, 1};
int arry[4] = {0, 0, 1, 1};

void foo(int a) {
    v.resize(a / 2 + 1, vector<int>(a / 2 + 1));

    for (int i = 1; i <= a; i += 2) {
        for (int j = 1; j <= a; j += 2) {
            for (int k = 0; k < 4; ++k) {
                tmparr[k] = original[i + arry[k]][j + arrx[k]];
            }
            sort(tmparr, tmparr + 4, greater<int>());
            v[i / 2 + 1][j / 2 + 1] = tmparr[1];
        }
    }

    original = v;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    original.resize(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> original[i][j];

    while (n > 1) {
        foo(n);
        n /= 2;
    }

    cout << original[1][1] << '\n';

}
