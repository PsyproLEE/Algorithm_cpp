#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int n, m;
vector<vector<int>> land;
unordered_map<int, int> oil_sizes;
vector<vector<int>> oil_id_map;


int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dfs(int x, int y, int id)
{
    stack<pair<int,int>> s;
    s.push({x,y});
    oil_id_map[x][y] = id;
    int area = 1;

    while (!s.empty())
    {
        int cx = s.top().first;
        int cy = s.top().second;
        s.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

            if (land[nx][ny] == 1 && oil_id_map[nx][ny] == -1)
            {
                oil_id_map[nx][ny] = id;
                s.push({nx, ny});
                area++;
            }
        }
    }

    oil_sizes[id] = area;
    return area;
}

int solution(vector<vector<int>> input_land)
{
    land = input_land;
    n= land.size();
    m = land[0].size();
    
    oil_id_map.assign(n, vector<int>(m, -1));
    
    int id = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (land[i][j] == 1 && oil_id_map[i][j] == -1)
            {
                dfs(i, j, id++);
            }
        }
    }
    
    int max_oil = 0;
    for (int col = 0; col < m; col++) {
        unordered_set<int> done;
        int sum = 0;
        for (int row = 0; row < n; row++) {
            int id = oil_id_map[row][col];
            if (id != -1 && done.find(id) == done.end()) {
                done.insert(id);
                sum += oil_sizes[id];
            }
        }
        max_oil = max(max_oil, sum);
    }
    return max_oil;
}

