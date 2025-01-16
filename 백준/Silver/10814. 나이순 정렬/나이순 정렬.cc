#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n; cin >> n;
    vector<tuple<int,int,string>> v(n);
    for (int i = 0; i < n; i++) {
        int age;
        string name;
        cin >> age >> name;
        v[i] = make_tuple(age, i, name); 
    }

    sort(v.begin(), v.end(), [](const tuple<int, int, string> &a, const tuple<int, int, string> &b) {
        if (get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
        return get<1>(a) < get<1>(b);
    });

    for (int i =0; i<n ; i++)
        cout << get<0>(v[i]) << ' ' << get<2>(v[i]) << '\n';
}
