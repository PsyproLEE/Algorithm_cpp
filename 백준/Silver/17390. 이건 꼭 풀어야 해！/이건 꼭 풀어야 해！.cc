#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    vector<long long> v (n+1,0);
    vector<long long> sum(n+1,0);
    
    for (int i = 1; i<=n; ++i){
        cin >> v[i];
        sum[i] =sum[i-1] + v[i];
    }

    sort(v.begin(),v.end());
    
    for (int i = 1; i<=n; ++i){
        sum[i] =sum[i-1] + v[i];
    }

    while (q--){
        int i, j;
        cin >> i >> j;
        cout << sum[j] - sum[i-1] << '\n';
    }
}
