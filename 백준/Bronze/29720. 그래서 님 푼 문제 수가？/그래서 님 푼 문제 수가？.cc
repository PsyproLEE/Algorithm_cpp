#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n,m,k; cin >> n >> m >> k;
    int min , max;
    min = n - (m * k);
    if (min <0) min = 0;
    max = n - (m * k) + (m-1);
    cout << min << " " << max;
}