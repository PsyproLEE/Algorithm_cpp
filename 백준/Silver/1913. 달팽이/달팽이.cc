#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, find_num;
    cin >> n >> find_num;

    vector<vector<int>> snail(n, vector<int>(n, 0));

    // 이동 방향: 아래, 오른쪽, 위, 왼쪽
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    int dir = 0;

    int current_x = 0;
    int current_y = 0;
    int current_num = n * n;

    // find_num의 좌표를 저장할 변수
    int find_x, find_y;

    while (current_num > 0) {
        snail[current_x][current_y] = current_num;

        if (current_num == find_num) {
            find_x = current_x + 1;
            find_y = current_y + 1; 
        }
        
        current_num--;

        int next_x = current_x + dx[dir];
        int next_y = current_y + dy[dir];

        if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n || snail[next_x][next_y] != 0) {
            dir = (dir + 1) % 4;
            next_x = current_x + dx[dir];
            next_y = current_y + dy[dir];
        }

        current_x = next_x;
        current_y = next_y;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << snail[i][j] << " ";
        }
        cout << '\n';
    }

    cout << find_x << " " << find_y << '\n';

    return 0;
}