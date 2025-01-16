#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n; cin >> n;
    vector<string> v;
    for (int i = 0; i < n; i++) {
        string s; bool is = false;
        cin >> s;
        for (int j =0; j < v.size(); j++){
            if (s == v[j]) {is = true; break;}
        }
        if(!is) v.push_back(s);
    }

    sort(v.begin(), v.end(), [](string &a, string &b) {
        if (a.length() != b.length())  return a.length() < b.length();
        return a < b;
    });

    for (int i =0; i<v.size() ; i++)
        cout << v[i]<< '\n';
}
