#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n+1,vector<int>(m+1,0));
    vector<vector<int>> sum(n+1,vector<int>(m+1,0));


    for(int i =1; i<=n; ++i){
        for (int j =1; j<=m; ++j){
            cin >> v[i][j];
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + v[i][j]; 
        }
    }

    int k ; cin >> k;
    while(k--){
        int i, j ,x, y;
        cin >> i >> j >> x >> y;
        
        cout << sum[x][y] - sum[i - 1][y] - sum[x][j - 1] + sum[i - 1][j - 1] << '\n';
        
    }

    
}
