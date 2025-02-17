#include <iostream>
#include <queue>
#include <vector>
#include <tuple> 

using namespace std;

int T, l, s_x, s_y, dest_x, dest_y;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

void bfs() {
    queue<tuple<int, int, int>> q;
    vector<vector<bool>> visited(l, vector<bool>(l, false));

    q.push(make_tuple(s_x, s_y, 0));  
    visited[s_x][s_y] = true;

    while (!q.empty()) {
        tuple<int, int, int> cur = q.front(); 
        q.pop();

        int cur_x = get<0>(cur);
        int cur_y = get<1>(cur);
        int cnt = get<2>(cur);

        if (cur_x == dest_x && cur_y == dest_y) {
            cout << cnt << '\n';
            return;
        }

        for (int i = 0; i < 8; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];

            if (next_x >= 0 && next_x < l && next_y >= 0 && next_y < l) {
                if (!visited[next_x][next_y]) {
                    visited[next_x][next_y] = true;
                    q.push(make_tuple(next_x, next_y, cnt + 1));  
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> l;
        cin >> s_x >> s_y;
        cin >> dest_x >> dest_y;
        
        bfs();
    }
}
