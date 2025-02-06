#include <iostream>
using namespace std;

int countFactor(long long n, int a) {
    int count = 0;
    while (n > 0) {
        count += n / a;
        n /= a;
    }
    return count;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n; 
    int a;
    cin >> n >> a;

    int ans = countFactor(n, a);  
    cout << ans << '\n';

    return 0;
}
