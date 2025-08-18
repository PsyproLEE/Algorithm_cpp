#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
using ll = long long;
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int L, R, C;

struct od
{
    int z, y, x, minutes;
};

int bfs( vector<vector<vector<char>>> &v , vector<vector<vector<int>>> &visited, od st){
    queue<tuple<int,int,int,int>> q;


    q.push({st.z,st.y, st.x, st.minutes});
    visited[st.z][st.y][st.x] = 1;
    
    while(!q.empty()){
        od cur;
        od nxt;

        tie(cur.z, cur.y ,cur.x, cur.minutes) = q.front(); q.pop();

        for(int i =0 ;i<6; ++i){
            nxt.z = cur.z +dz[i];
            nxt.y = cur.y +dy[i];
            nxt.x = cur.x +dx[i];
            nxt.minutes = cur.minutes + 1;
            if(nxt.z >= 0 && nxt.z <L && nxt.y >= 0 && nxt.y <R && nxt.x >= 0 && nxt.x <C){
                if(visited[nxt.z][nxt.y][nxt.x] != 1 && v[nxt.z][nxt.y][nxt.x] == '.'){
                    q.push({nxt.z, nxt.y, nxt.x, nxt.minutes});
                    visited[nxt.z][nxt.y][nxt.x] = 1;
                }
                else if(v[nxt.z][nxt.y][nxt.x] == 'E'){
                    return nxt.minutes;
                }
            }

        }
    }
return 0;


}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    
    while(1){
    cin >> L >> R >> C;
    if(L == 0&&R == 0&&C == 0) return 0;
    vector<vector<vector<char>>> v(L, vector<vector<char>>(R, vector<char>(C)));
    vector<vector<vector<int>>> visited(L, vector<vector<int>>(R, vector<int>(C,0)));
    od st;

    for (int i = 0; i < L; ++i)
    {
        for (int j = 0; j < R; ++j)
        {
            for (int k = 0; k < C; ++k)
            {
                cin >> v[i][j][k];
                if (v[i][j][k] == 'S')
                {
                    st.z = i;
                    st.y = j;
                    st.x = k;
                    st.minutes = 0;
                }
            }
        }
    }
    int ans = bfs(v,visited,st);
    ans ? cout << "Escaped in " << ans << " minute(s).\n" :cout << "Trapped!\n";
    }
    return 0;
}