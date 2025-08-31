// 20208. 진우의 민트초코우유
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int n, m, h;
 
// 집의 위치
int sx, sy;
 
// 정답을 담을 변수
int ans;
 
// 민초우유의 좌표
vector<pair<int, int>> point;
// 해당 민초를 방문했는지 체크
vector<int> visited;
 
void recur(int x, int y, int health, int cnt)
{
    // 항상 현재 위치에서 집으로 갈 수 있는 지 파악하고
    // 민트초코우유의 최대 개수를 갱신한다.
    int go_home = abs(x - sx) + abs(y - sy);
    if (health >= go_home)
    {
        ans = max(ans, cnt);
    }
 
    for (int i = 0; i < point.size(); i++)
    {
        // i번째 지점까지 가는데 필요한 hp량
        int need_hp = abs(x - point[i].first) + abs(y - point[i].second);
        
        // 방문한 지점이면 continue
        if (visited[i]) continue;
        // 현재 위치에서 해당 위치까지 갈 수 없는 경우
        if (health < need_hp) continue;
        
        visited[i] = 1;
        recur(point[i].first, point[i].second, health - need_hp + h, cnt + 1);
        visited[i] = 0;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n >> m >> h;
 
    int a;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a;
            // 집의 위치 설정
            if (a == 1)
            {
                sx = i, sy = j;
            }
            // 민초우유의 좌표 파악
            else if (a == 2)
            {
                point.push_back(make_pair(i, j));
            }
        }
    }
 
    // 민초우유의 개수에 맞추어 방문체크 배열 생성
    visited.resize(point.size(), 0);
 
    recur(sx, sy, m, 0);
 
    cout << ans;
 
    return 0;
}
