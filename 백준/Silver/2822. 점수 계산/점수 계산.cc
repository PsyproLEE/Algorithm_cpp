#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    vector<pair<int,int>> v(8);
    int sum = 0;

    for (int i =0 ;i < 8 ;i ++){
        cin >> v[i].first;
        v[i].second = i+1;
    }
    vector<int> order;    
    sort(v.rbegin(),v.rend());
    for (int i =0; i< 5; i++){
        sum += v[i].first;
        order.push_back(v[i].second);
    }
    cout << sum << '\n';

    sort(order.begin(), order.end());

    for (int a : order)
        cout << a << ' ';
    
}
