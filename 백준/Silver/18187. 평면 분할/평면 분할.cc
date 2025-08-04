#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int n; cin>> n;
    vector<int> dp(n+1, 0);
    dp[1] = 2;
    dp[2] = 4;
    int up = 2;
    for(int i = 3; i<= n; ++i){
        if (i % 3 ==0)
            up++;
        else if(i % 3 == 1);
        else 
            up++;
        dp[i] =  dp[i-1] + up;
        }
    cout << dp[n];
    return 0;
}