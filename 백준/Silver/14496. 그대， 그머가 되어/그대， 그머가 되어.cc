#define MAXN 1001
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
bool visited[MAXN] = {false,};

int bfs(int start, int end, vector<vector<int>>& v){
    fill(visited, visited + MAXN, false); 

    queue<pair<int,int>> q;

    if (end == start ) return 0;
    q.push({start, 0});
    visited[start] = true;
    
    while(!q.empty()){
        int curr = q.front().first;
        int distance = q.front().second;
        q.pop();

        for(int next : v[curr]){
            if(next == end) return distance + 1;
            if(!visited[next]){
                visited[next] = true;
                q.push({next, distance + 1});
            }
        }
    }
    return -1;
}

int main(){
    int a, b, n, m;
    cin >> a >> b;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1); 

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << bfs(a, b, adj);
    return 0;
}
