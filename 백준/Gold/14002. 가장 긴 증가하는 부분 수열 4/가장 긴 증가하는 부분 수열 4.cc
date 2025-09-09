#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n; cin >> n;

    vector<int> v(n);
    for(int i =0; i<n; ++i){
        cin >> v[i];
    }

    vector<int> dp(n,1) , prev(n, -1);

    for(int i =0; i<n; ++i){
        for(int j = 0; j< i; ++j){
            if(v[j] < v[i] && dp[j] + 1 > dp[i]){
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }

        }
    }

    int last = max_element(dp.begin(), dp.end()) - dp.begin();
    vector<int> lis;
    for (int cur = last; cur != -1; cur = prev[cur]) lis.push_back(v[cur]);
    reverse(lis.begin(), lis.end());
    
    cout << *max_element(dp.begin(), dp.end()) << '\n';
    for(int x : lis) cout << x << ' ';
    return 0;
}