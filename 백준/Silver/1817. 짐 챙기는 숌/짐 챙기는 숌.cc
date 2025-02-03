#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n , m ; cin >> n >> m;
    int sum = 0; int cnt;
    if (n>0) cnt = 1;
    else cnt = 0;
    while(n--){
        int a; cin >> a;
        if (sum + a > m) {cnt++; sum = 0; sum+= a;}
        else sum += a;
    }
    cout << cnt;
}
