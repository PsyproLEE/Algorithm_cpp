#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for (int i =0 ; i <n ; i++){
        
        long long x ; cin >> x;
        
        long long root = (long long)sqrt(x);
        if (root * root == x) {
            cout << 1 << " ";
        } else {
            cout << 0 << " ";
        }

    }
}

