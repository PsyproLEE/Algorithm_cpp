#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n; cin >> n;
    vector<int> v;
    int ans;
    if (n < 100){
        ans = n; 
    }
    else {
        ans = 99;
    
    
    if ( n >= 100 && n <= 1000){
        for(int i =100; i<=n ; ++i){
            int a = i / 100; 
            int b = (i / 10) % 10; 
            int c = i % 10; 
            
            if (b - a == c - b) { 
                ans++;
                }
            }
        }
    }
     cout << ans;

}