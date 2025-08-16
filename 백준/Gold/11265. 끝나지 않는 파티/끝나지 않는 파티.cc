#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<vector<ll>> adj(n+1, vector<ll>(n+1,0));

    for(int i = 1; i<n+1; ++i){
        for(int j = 1; j < n+1; ++j){
            cin >> adj[i][j];
        }
    }

    for(int k = 1; k<= n; ++k){
        for(int i = 1; i <= n ; ++i){
            for(int j =1 ; j<= n ; ++j){
                ll through = adj[i][k] + adj[k][j];
                adj[i][j] = min(adj[i][j], through);
            }
        }
    }

    for (int i =0 ; i< m ;++i){
        int A, B ,C;
        cin >> A >> B >> C;
        cout << (adj[A][B] <= C ? "Enjoy other party" : "Stay here") << '\n';
    }
    return 0;
}