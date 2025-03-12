#include <iostream>
#include <cstring>

using namespace std;
const int mod = 10'007; 
int n, k;
long long dp[1001][1001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> k;
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;


    for(int i = 2; i<= n; ++i){
        for(int j = 0; j<= min(i,k); ++j){
            if(j == 0) dp[i][0] = 1;
            else if (j == i) dp[i][i] = 1;
            else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % mod;
        }
    }
    cout << dp[n][k];
   }