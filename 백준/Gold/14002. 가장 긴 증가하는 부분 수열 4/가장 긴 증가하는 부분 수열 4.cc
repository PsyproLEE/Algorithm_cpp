#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int arr[1001], dp[1001] ={0,}, prev[1001];
    fill(prev, prev + n, -1);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    
    for (int i =0; i<n;++i){   
        dp[i] = 1;
        for (int j =0; j<i; ++j){
            if (arr[i]> arr[j] && dp[j]+1 > dp[i]){
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
    }

    int last = max_element(dp,dp+n) - dp;
    vector<int> lis;
    for(int cur = last ; cur != -1; cur = prev[cur]){
        lis.push_back(arr[cur]);
    }
    reverse(lis.begin(), lis.end());
    cout << dp[last] <<'\n';
    for(int x: lis) cout << x << ' ';
    return 0;
}