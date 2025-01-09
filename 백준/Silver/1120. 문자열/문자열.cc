#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string a, b;
    cin >> a >> b;

    int ans = 51; 

    size_t size_range = b.size() - a.size();
    for (size_t i = 0; i <= size_range; i++) {
        string temp = b.substr(i, a.size());
        int cnt = 0;
        for (size_t j = 0; j < a.size(); j++) {
            if (a[j] != temp[j]) {
                cnt++;
            }
            if (cnt >= ans) break; 
        }
        ans = min(ans, cnt);
    }

    cout << ans;
    return 0;
}
