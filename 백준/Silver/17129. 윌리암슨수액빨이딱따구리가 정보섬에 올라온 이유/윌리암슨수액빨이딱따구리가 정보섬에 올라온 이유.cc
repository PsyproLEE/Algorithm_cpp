#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
int n, m;
int st_x, st_y;

int bfs(vector<string> &v, vector<vector<bool>> &visited)
{
    queue<tuple<int, int, int>> q;
    q.push({st_y, st_x, 0});
    visited[st_y][st_x] = true;

    while (!q.empty())
    {
        int cy, cx, dis;
        tie(cy, cx, dis) = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (nx >= 0 && ny >= 0 && ny < n && nx < m
                && !visited[ny][nx] && v[ny][nx] != '1')
            {
                visited[ny][nx] = true;
                int nd = dis + 1;

                if (v[ny][nx] == '3' || v[ny][nx] == '4' || v[ny][nx] == '5')
                    return nd;

                q.push({ny, nx, nd});
            }
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];              
    }

    st_y = st_x = -1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (v[i][j] == '2') { st_y = i; st_x = j; }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int ans = bfs(v, visited);

    if (ans != -1) {
        cout << "TAK\n" << ans;
    } else {
        cout << "NIE";
    }
    return 0;
}
