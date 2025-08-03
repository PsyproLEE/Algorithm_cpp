#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>

using namespace std;
using ll = long long;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n + 2, vector<int>(m + 2, 0));
    vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));
    priority_queue<tuple<int, int, int>> pq;
    unordered_set<int> us;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> v[i][j];
            if (i == 1 || j == 1 || i == n || j == m)
            {
                pq.push({v[i][j], i, j});
                us.insert(v[i][j]);
            }
        }
    }
    int k;
    cin >> k;
    vector<pair<int, int>> ans;
    while (k--)
    {
        ans.push_back({get<1>(pq.top()), get<2>(pq.top())});
        us.erase(get<0>(pq.top()));
        int cy, cx;
        cy = get<1>(pq.top());
        cx = get<2>(pq.top());
        visited[cy][cx] = true;
        pq.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx, ny;
            nx = cx + dx[i];
            ny = cy + dy[i];
            if (ny >= 1 && ny <= n && nx >= 1 && nx <= m)
            {
                if (!visited[ny][nx] && !us.count(v[ny][nx]))
                {
                    pq.push({v[ny][nx], ny, nx});
                    us.insert(v[ny][nx]);
                }
            }
        }
    }
    for (auto a : ans)
    {
        cout << a.first << ' ' << a.second << '\n';
    }
    return 0;
}