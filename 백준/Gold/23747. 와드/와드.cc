#include <bits/stdc++.h>
using namespace std;

int R, C;
vector<string> board;
vector<vector<int>> comp_id;                 // -1: 미라벨링
vector<vector<pair<int,int>>> cells;         // 각 컴포 좌표 목록
vector<char> comp_revealed;                  // 컴포넌트 공개 여부
vector<string> ans;                          // 출력격자
int dy[4] = {-1, 1, 0, 0};                   // U, D, L, R
int dx[4] = { 0, 0,-1, 1};

void build_components(){
    comp_id.assign(R, vector<int>(C, -1));
    cells.clear();
    int cur = 0;
    for (int y = 0; y < R; ++y){
        for (int x = 0; x < C; ++x){
            if (comp_id[y][x] != -1) continue;
            comp_id[y][x] = cur;
            cells.push_back({});
            cells[cur].push_back({y, x});
            queue<pair<int,int>> q;
            q.push({y, x});
            while (!q.empty()){
                int cy = q.front().first;
                int cx = q.front().second;
                q.pop();
                for (int dir=0; dir<4; ++dir){
                    int ny = cy + dy[dir], nx = cx + dx[dir];
                    if (ny<0||ny>=R||nx<0||nx>=C) continue;
                    if (comp_id[ny][nx] != -1) continue;
                    if (board[ny][nx] != board[cy][cx]) continue;
                    comp_id[ny][nx] = cur;
                    cells[cur].push_back({ny, nx});
                    q.push({ny, nx});
                }
            }
            ++cur;
        }
    }
    comp_revealed.assign(cells.size(), 0); // 공개 여부 초기화
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C;
    board.resize(R);
    for (int i=0;i<R;++i) cin >> board[i];

    build_components();

    int sy, sx;
    cin >> sy >> sx;
    --sy; --sx;

    string log; 
    cin >> log;

    ans.assign(R, string(C, '#'));

    for (char cmd : log){
        if (cmd == 'W'){
            int id = comp_id[sy][sx];
            if (!comp_revealed[id]) {                 // 처음 공개하는 컴포넌트만 순회
                comp_revealed[id] = 1;
                for (auto &p : cells[id]) {
                    ans[p.first][p.second] = '.';
                }
            }
        } else {
            if (cmd=='U'){ sy += dy[0]; sx += dx[0]; }
            else if(cmd=='D'){ sy += dy[1]; sx += dx[1]; }
            else if(cmd=='L'){ sy += dy[2]; sx += dx[2]; }
            else if(cmd=='R'){ sy += dy[3]; sx += dx[3]; }
        }
    }
    auto paint = [&](int y, int x){
        if (0 <= y && y < R && 0 <= x && x < C) ans[y][x] = '.';
    };
    paint(sy, sx);
    for (int dir = 0; dir < 4; ++dir) paint(sy + dy[dir], sx + dx[dir]);
    
    for (int i=0;i<R;++i) cout << ans[i] << '\n';
    return 0;
}
