#include <iostream>
#include <cstring>

using namespace std;
const int mod = 10'007; 
int n;
int dp[1001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n;
    memset(dp,0,sizeof(dp));

    dp[0] = 1;
    dp[1] = 1;
    
    for(int i = 2; i<= n; ++i){
        dp[i] = (dp[i-1] + dp[i-2]) % mod;
    }
    cout << dp[n];
   }