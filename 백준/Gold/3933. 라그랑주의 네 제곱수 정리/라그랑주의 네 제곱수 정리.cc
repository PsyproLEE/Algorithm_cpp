#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 32768;
vector<int> count_sums(MAX_N, 0);

void precompute() {
    for (int a = 0; a * a < MAX_N; ++a) {
        int a2 = a * a;
        for (int b = a; a2 + b * b < MAX_N; ++b) {
            int ab = a2 + b * b;
            for (int c = b; ab + c * c < MAX_N; ++c) {
                int abc = ab + c * c;
                for (int d = c; abc + d * d < MAX_N; ++d) {
                    int total = abc + d * d;
                    count_sums[total]++;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    precompute();

    int n;
    while (cin >> n && n != 0) {
        cout << count_sums[n] << '\n';
    }

    return 0;
}
