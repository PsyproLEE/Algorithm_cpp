#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    unordered_map<int, int> map;
    int ans = 0;
    for(int i =0; i<n; ++i){
        int num; cin >> num;
        map[num]++;
        ans = max(ans, map[num]);
    }
    cout << ans;

}