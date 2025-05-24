#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int dist[401][401];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int V, E;
    cin >> V >> E;

    
    for (int i = 1; i <= V; ++i)
        for (int j = 1; j <= V; ++j)
            dist[i][j] = (i == j ? 0 : INF);

    for (int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c); 
    }

    
    for (int k = 1; k <= V; ++k)
        for (int i = 1; i <= V; ++i)
            for (int j = 1; j <= V; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    int answer = INF;
    for (int i = 1; i <= V; ++i) {
        for (int j = 1; j <= V; ++j) {
            if (i != j && dist[i][j] < INF && dist[j][i] < INF) {
                answer = min(answer, dist[i][j] + dist[j][i]);  
            }
        }
    }

    if (answer == INF) cout << -1 << '\n';
    else cout << answer << '\n';

    return 0;
}
