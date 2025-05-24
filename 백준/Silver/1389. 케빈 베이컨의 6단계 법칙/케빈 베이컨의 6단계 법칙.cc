#include <iostream>
using namespace std;

const int INF = 1e9;
int dist[101][101];

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            dist[i][j] = (i == j ? 0 : INF);

    
    for (int i = 1; i <= M; ++i) {
        int a, b;
        cin >> a >> b;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }
    
    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    int ans = 0;
    int min_sum = INF;

    for (int i = 1; i <= N; ++i) {
        int sum = 0;
        for (int j = 1; j <= N; ++j)
            sum += dist[i][j];

        if (sum < min_sum) {
            min_sum = sum;
            ans = i;
        }
    }

    cout << ans << '\n';
    return 0;
}
