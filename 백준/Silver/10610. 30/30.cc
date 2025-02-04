#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s; 
    cin >> s;
    
    vector<int> v;
    int sum = 0;
    
    for (char c : s) {
        int num = c - '0';
        v.push_back(num);
        sum += num;
    }

    sort(v.rbegin(), v.rend()); 

    if (sum % 3 == 0 && find(v.begin(), v.end(), 0) != v.end()) {
        for (int x : v) cout << x;
    } else {
        cout << -1;
    }
}
