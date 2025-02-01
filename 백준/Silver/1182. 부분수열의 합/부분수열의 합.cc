#include <iostream>
#include <vector>
using namespace std;

int countSubsequences(vector<int>& v, int idx, int s, int sum) {
    if (idx == v.size()) return (sum == s) ? 1 : 0;

    return countSubsequences(v, idx + 1, s, sum) 
         + countSubsequences(v, idx + 1, s, sum + v[idx]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, s; 
    cin >> n >> s;
    vector<int> v(n);

    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int result = countSubsequences(v, 0, s, 0);
    if (s == 0) result--; // 공집합 제외

    cout << result;
}
