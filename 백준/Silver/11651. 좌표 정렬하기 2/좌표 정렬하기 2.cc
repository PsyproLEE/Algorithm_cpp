#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n; cin >> n;
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second; 
    }

    sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        if (a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    });

    for (int i =0; i<n ; i++)
        cout << get<0>(v[i]) << ' ' << get<1>(v[i]) << '\n';
}
