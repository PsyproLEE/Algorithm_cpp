#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<long long> v (n+1,0);
    vector<long long> sum(n+1,0);
    for (int i = 1; i<=n; ++i){
        cin >> v[i];
        sum[i] =sum[i-1] + v[i];
    }
    long long ans = 0;
    for(int j = 1; j <= n; ++j){
        ans += v[j] * (sum[n] - sum[j]);
    }
    cout << ans;
}
