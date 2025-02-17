#include <iostream>
#include <vector>
using namespace std;

vector<int> Prime_num; // 소수 리스트
vector<bool> is_prime(1'000'001, true);

void makePrime_num_table() {
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= 1'000'000; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= 1'000'000; j += i) {
                is_prime[j] = false;
            }
        }
    }

    Prime_num.push_back(2);
    for (int i = 3; i <= 1'000'000; i += 2) {
        if (is_prime[i]) Prime_num.push_back(i);
    }
}

void find_Goldbach(int n) {
    for (int i = 0; Prime_num[i] <= n / 2; ++i) {
        int a = Prime_num[i];
        int b = n - a;
        
        if (is_prime[b]) { 
            cout << n << " = " << a << " + " << b << '\n';
            return;
        }
    }

    cout << "Goldbach's conjecture is wrong.\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    makePrime_num_table(); 

    int x;
    while (cin >> x) {
        if (x == 0) return 0;
        find_Goldbach(x);
    }
}
