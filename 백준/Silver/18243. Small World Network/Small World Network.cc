#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> dist(N+1, vector<int>(N+1, INF));

    for (int i = 1; i <= N; ++i) dist[i][i] = 0;

    for (int i =0; i<M; ++i){
        int a, b;
        cin >> a>> b;
        dist[a][b] = 1;
        dist[b][a] = 1;

    }

    for(int k = 1; k<= N; ++k){
        for (int i = 1; i<= N ; ++i){
            for (int j = 1; j<= N; ++j){
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] +dist[k][j]);
            }
        }
    }

    for (int i = 1; i<= N; ++i){
        for(int j = i + 1 ; j<= N ; ++j){
            if (dist[i][j] >= 7){
                cout << "Big World!" << endl;
                return 0;
            }
        }
    }
    cout << "Small World!" << endl;
    return 0;
}