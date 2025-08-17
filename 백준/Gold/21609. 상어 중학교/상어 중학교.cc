#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
int n, m;
vector<vector<int>> board; // 1..n, -2=빈칸, -1=검은 블록, 0=무지개, 1..m=색블록

struct Group {
    int size = 0;
    int rainbow = 0;
    int sy = -1, sx = -1;       // 표준 블록(무지개 제외, 행 최소 -> 열 최소)
    vector<pii> cells;          // 그룹 전체 좌표(무지개 포함)
    bool valid = false;
};

inline void updStandard(int y, int x, int &sy, int &sx) {
    // 무지개 제외 블록만 들어온다고 가정
    if (sy == -1) { sy = y; sx = x; return; }
    if (y < sy || (y == sy && x < sx)) { sy = y; sx = x; }
}

bool better(const Group& a, const Group& b) {
    if (!b.valid) return a.valid;   
    if (!a.valid) return false;
    if (a.size != b.size) return a.size > b.size;
    if (a.rainbow != b.rainbow) return a.rainbow > b.rainbow;
    if (a.sy != b.sy) return a.sy > b.sy;   // 표준블록 행 큰 것 우선
    return a.sx > b.sx;                     // 열 큰 것 우선
}

Group bfs_group(int sy, int sx, vector<vector<int>>& vis) {
    Group g;
    int color = board[sy][sx];
    if (color <= 0) return g; // 시작은 일반 색만 가능

    queue<pii> q;
    q.push({sy, sx});
    vis[sy][sx] = 1;

    vector<vector<int>> vis_r(n+1, vector<int>(n+1, 0)); // 무지개 방문(그룹 내 전용)
    g.valid = true;

    g.cells.push_back({sy, sx});
    g.size = 1;
    g.sy = -1; g.sx = -1;
    updStandard(sy, sx, g.sy, g.sx);

    static int dy[4] = {1,-1,0,0};
    static int dx[4] = {0,0,1,-1};

    while (!q.empty()) {
        int y, x;
        tie(y, x) = q.front(); q.pop();
        for (int d = 0; d < 4; ++d) {
            int ny = y + dy[d], nx = x + dx[d];
            if (ny < 1 || ny > n || nx < 1 || nx > n) continue;

            if (board[ny][nx] == 0) { // 무지개
                if (vis_r[ny][nx]) continue;
                vis_r[ny][nx] = 1;
                q.push({ny, nx});
                g.cells.push_back({ny, nx});
                g.size++;
                g.rainbow++;
            } else if (board[ny][nx] == color && !vis[ny][nx]) { // 같은 색
                vis[ny][nx] = 1;
                q.push({ny, nx});
                g.cells.push_back({ny, nx});
                g.size++;
                updStandard(ny, nx, g.sy, g.sx);
            }
        }
    }

    // 그룹 유효성: 크기 >= 2, 일반 블록(표준블록 존재) 1개 이상
    if (g.size < 2 || g.sy == -1) g.valid = false;
    return g;
}

Group find_best_group() {
    vector<vector<int>> vis(n+1, vector<int>(n+1, 0));
    Group best;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (board[i][j] > 0 && !vis[i][j]) {
                Group g = bfs_group(i, j, vis);
                if (better(g, best)) best = g;
            }
        }
    }
    return best;
}

void remove_group(const Group& g) {
    for (auto &p : g.cells) {
        int y = p.first, x = p.second;
        board[y][x] = -2; // 빈칸으로
    }
}

void apply_gravity() {
    // 각 열마다 검은 블록(-1)을 경계로 아래로 떨어뜨림
    for (int col = 1; col <= n; ++col) {
        int write = n; // 채워 넣을 위치(아래부터)
        for (int row = n; row >= 1; --row) {
            if (board[row][col] == -1) {
                // 검은 블록은 고정, 위쪽 구간 write 리셋
                write = row - 1;
            } else if (board[row][col] >= 0) {
                // 낙하 대상(무지개/일반 색)
                if (write != row) {
                    board[write][col] = board[row][col];
                    board[row][col] = -2;
                }
                write--;
            } else {
                // 빈칸(-2)면 무시
            }
        }
    }
}

void rotate_ccw() {
    vector<vector<int>> nb(n+1, vector<int>(n+1, -2));
    // 반시계 90도: new[i][j] = old[j][n - i + 1] (1-indexed)
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            nb[i][j] = board[j][n - i + 1];
    board.swap(nb);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    board.assign(n+1, vector<int>(n+1, -2));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> board[i][j];

    long long total_score = 0;

    while (true) {
        Group best = find_best_group();
        if (!best.valid) break; // 더 이상 그룹 없음 -> 종료

        // 점수 획득
        total_score += 1LL * best.size * best.size;

        // 제거
        remove_group(best);

        // 중력
        apply_gravity();

        // 반시계 90도 회전
        rotate_ccw();

        // 중력
        apply_gravity();
    }

    cout << total_score << "\n";
    return 0;
}
