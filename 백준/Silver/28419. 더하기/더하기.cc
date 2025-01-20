#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    vector<int> v(n);
    for (int i =0; i< n; ++i){
        cin >> v[i];
    }

    long long odd_sum = 0, even_sum = 0;

    for (int j = 0; j< n ; j = j+2){
        even_sum += v[j];
    } 

    for (int k = 1; k< n ;k = k+2){
        odd_sum += v[k];
    }
    if ( n == 3 && odd_sum < even_sum) cout << -1;
    else cout << abs(even_sum - odd_sum);
}