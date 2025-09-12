#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int dp[1001][1001];

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    string A, B; cin >> A >> B;

    for (int i = 1; i<=A.size(); ++i){
        for(int j =1; j <= B.size(); ++j){

            if(A[i-1] == B[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout << dp[A.size()][B.size()] <<'\n';
    return 0;
}