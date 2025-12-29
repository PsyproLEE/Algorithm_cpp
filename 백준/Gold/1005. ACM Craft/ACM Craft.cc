#include <iostream>
#include <vector>

using namespace std;

int n, k, x, y, w, t;
vector<int> tim;
vector<vector<int>> directed;
vector<int> dp;
int ans = 0;

int find_ans(int a){

    if ((dp[a] != -1)) return dp[a];
    
    int mx = 0;
    for (int b : directed[a]){
        mx = max(mx, find_ans(b));
    }

    return dp[a] = tim[a] + mx;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--){
        ans = 0;
        cin >> n >> k;
        tim.assign(n+1,0);

        for(int i =1; i<=n; ++i){
            cin >> tim[i];
        }

        directed.assign(n+1, {});
        dp.assign(n+1, -1);
        for(int i =0 ; i<k; ++i){
            cin >> x >> y;
            directed[y].push_back(x);
        }
        
        cin >> w;
        cout << find_ans(w) << '\n';
    }
    return 0;
}