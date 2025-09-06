#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct subject{
    int value, time;
};
vector<subject> item;
vector<vector<int>> dp;
int N , K;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    
    item.assign(K+1,subject());
    dp.assign(K+1,vector<int>(N+1,0));

    for(int i =1; i<=K; ++i){
        cin >> item[i].value >> item[i].time;
    }

    for(int i = 1; i <= K; ++i ){
        for(int j = 1 ; j<=N; ++j){
            if(item[i].time > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-item[i].time]+item[i].value);
            }
        }
    }
    cout << dp[K][N] << '\n';
    return 0;
}