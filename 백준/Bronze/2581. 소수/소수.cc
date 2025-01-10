#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> m >> n;

    int minPrime = -1;
    long long sum = 0;

    for (int num = m; num <= n; num++) {
        if (num < 2) continue; 

        bool isPrime = true;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            if (minPrime == -1) minPrime = num; 
            sum += num;
        }
    }

    if (minPrime != -1) {
        cout << sum << '\n' << minPrime;
    } else {
        cout << -1;
    }

    return 0;
}
