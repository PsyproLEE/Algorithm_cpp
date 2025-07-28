#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    vector<vector<ll>> dp(n+1,vector<ll>(3,1));
    for (int i = 1; i < n; ++i){
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % 9901;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % 9901;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % 9901;
    }
    cout << (dp[n-1][0] + dp[n-1][1] + dp[n-1][2]) % 9901;
    return 0;
}