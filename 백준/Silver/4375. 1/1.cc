#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    while(cin>>n){
        long long a = 1;
        int cnt = 1;
        while(a % n != 0){
            a = a * 10 + 1;
            a %= n;
            cnt++;
        }
        cout << cnt << '\n';
    }
    
}