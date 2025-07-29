#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <algorithm>
 
using namespace std;
 
long long n, m, k;
vector<pair<long long, long long>> beer;
priority_queue<long long> pq;
 
bool compare(pair<long long, long long> &a, pair<long long, long long> &b) {
    if (a.first < b.first) return true;
    else if (a.first == b.first) return a.second > b.second;
    return false;
}
 
int main() {
    ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
    cin >> n >> m >> k;
    
    for (int i = 0; i < k; i++) {
        long long prefer, alc;
        cin >> prefer >> alc;
        beer.push_back({alc, prefer});  // alc: 도수, prefer: 선호도
    }
    
    sort(beer.begin(), beer.end(), compare);  // 도수 낮은 순

    long long sum = 0;
    
    for (int i = 0; i < k; i++) {
        pq.push(-beer[i].second);  // min-heap
        sum += beer[i].second;
        
        if (pq.size() > n) {
            sum -= -pq.top();  // 원래 음수로 넣었으니 다시 양수로 빼줘야 함
            pq.pop();
        }
        
        if (pq.size() == n && sum >= m) {
            cout << beer[i].first;
            return 0;
        }
    }
 
    cout << -1;
    return 0;
}
