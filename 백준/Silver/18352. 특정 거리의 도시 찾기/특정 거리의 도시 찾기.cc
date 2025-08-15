#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int n, m, k, x;

    cin >> n >> m >> k >> x;

    vector<vector<pair<int,int>>> g(n+1);
    for(int i = 0; i<m; ++i){
        int u, v;

        cin >> u >> v;
        g[u].push_back({v,1});
    }

    vector<ll> dist(n+1,1e9);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,x});
    dist[x] = 0;

    while(!pq.empty()){
        int cd, u;
        tie(cd, u) = pq.top(); pq.pop();
        if(dist[u] != cd) continue;
        for(size_t i =0; i<g[u].size(); ++i){
            int v, w;
            tie(v,w) = g[u][i];
            int nd = cd + w;
            if(nd < dist[v]){
                dist[v] = nd;
                pq.push({nd,v});
            }
        }
    }

    bool any = false;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == k) {
            cout << i << '\n';
            any = true;
        }
    }
    if (!any) cout << -1 << '\n';
    return 0;

    return 0;
}