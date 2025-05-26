#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;
int V, E, K;

vector<vector<pair<int,int>>> graph;
vector<int> dist;

void dijkstra(int start){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[start] =0;
    pq.push({0,start});

    while(!pq.empty()){
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (cost > dist[now]) continue;

        for(auto &edge : graph[now]){
            int nextCost = cost + edge.second;
            int next = edge.first;
            

            if (nextCost < dist[next]){
                dist[next] = nextCost;
                pq.push({nextCost,next});
            }
        }
    }
}


int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> V >> E >> K;

    graph.resize(V+1);
    dist.assign(V+1, INF);

    for(int i = 0; i< E; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
    }

    dijkstra(K);

    for(int i =1; i<= V; ++i){
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }

    return 0;
}