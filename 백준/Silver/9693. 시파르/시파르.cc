#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x = 1;
    
    while(1){
        int n; cin >> n;
        if (n == 0) break;
        int cnt = 0;
        while (n >= 5) {
            cnt += n / 5;
            n /= 5;
        }   
        cout << "Case #" << x << ": " << cnt <<'\n';
        x++;
    }

    
}
