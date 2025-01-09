#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long arr[42] = {}; 
    long n;
    int res = 0;


    for (int i = 0; i < 10; i++) {
        cin >> n;
        arr[n % 42]++;
    }

    for (int a : arr) {
        if (a != 0) res++;
    }

    cout << res;
}
