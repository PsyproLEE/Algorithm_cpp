#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int n, c;
map<int, int> m;
map<int, int> order;  
vector<pair<int, int>> v;

bool bigger(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return order[a.first] < order[b.first];  
    }
    return a.second > b.second;  
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a;
    int cnt = 1;
    cin >> n >> c;

    while (n--) {
        cin >> a;
        m[a]++;  
        if (order[a] == 0) {  
            order[a] = cnt;
            cnt++;
        }
    }

    for (auto i : m) {
        v.push_back({i.first, i.second});  // (숫자, 빈도) 저장
    }

    sort(v.begin(), v.end(), bigger);  

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].second; j++) {
            cout << v[i].first << " ";  
        }
    }
}
