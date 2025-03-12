#include <iostream>
#include <cstring>

using namespace std;
const int mod = 1'000'000'007; 
int n, m;
int dp[1001][1001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m;
    memset(dp,0,sizeof(dp));

    dp[0][0] = 1;
    
    
    for(register int i = 1; i <=n; ++i){
        for(register int j = 1; j <=m ; ++j){
            dp[i][j] =(dp[i-1][j] + (dp[i][j-1] + dp [i-1][j-1])% mod )% mod;    
        }
    }
    cout << dp[n][m];

   }