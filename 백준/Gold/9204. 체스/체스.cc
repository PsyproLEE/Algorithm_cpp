#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int t;
bool visited[8][8];

struct Move {
    int x, y, cnt;
    vector<pair<int, int>> path;
};

int dx[4] = {1, 1, -1, -1};
int dy[4] = {1, -1, 1, -1};

void bfs(int strx, int stry, int desx, int desy) {
    queue<Move> q;
    fill(&visited[0][0], &visited[7][8], false);

    q.push({strx, stry, 0, {{strx, stry}}});
    visited[strx][stry] = true;

    while (!q.empty()) {
        Move cur = q.front();
        q.pop();

        if (cur.x == desx && cur.y == desy) {
            cout << cur.cnt << " ";
            for (auto &p : cur.path) {
                cout << char(p.first + 'A') << " " << p.second + 1 << " ";
            }
            cout << '\n';
            return;
        }

        for (int i = 0; i < 4; i++) {  
            for (int step = 1; step <= 4; step++) {  // 최대 7칸 이동 가능
                int nx = cur.x + dx[i] * step;
                int ny = cur.y + dy[i] * step;

                if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
                    if (!visited[nx][ny]) {
                        visited[nx][ny] = true;
                        vector<pair<int, int>> newPath = cur.path;
                        newPath.push_back({nx, ny});
                        q.push({nx, ny, cur.cnt + 1, newPath});
                    }
                } else {
                    break; // 체스판을 벗어나면 중지
                }
            }
        }
    }

    cout << "Impossible\n"; // 같은 색인데 도착할 수 없는 경우
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        char c1, c2;
        int y1, y2;
        cin >> c1 >> y1 >> c2 >> y2;

        int strx = c1 - 'A';
        int stry = y1 - 1;
        int desx = c2 - 'A';
        int desy = y2 - 1;

        // 색이 다르면 이동 불가능
        if ((strx + stry) % 2 != (desx + desy) % 2) {
            cout << "Impossible\n";
        } 
        // 출발지와 목적지가 같으면 0 출력
        else if (strx == desx && stry == desy) {
            cout << "0 " << c1 << " " << y1 << "\n";
        }
        else {
            bfs(strx, stry, desx, desy);
        }
    }
    return 0;
}
