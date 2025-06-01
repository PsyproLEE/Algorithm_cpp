#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int dy[4] = {-1, 0, 0, 1}; // N, W, E, S
int dx[4] = {0, -1, 1, 0};

int H, W;
vector<vector<int>> altitude;
vector<vector<pair<int, int>>> sink;

pair<int, int> find_sink(int y, int x) {
    if (sink[y][x] != make_pair(-1, -1)) return sink[y][x];

    int min_y = y, min_x = x;
    for (int d = 0; d < 4; d++) {
        int ny = y + dy[d];
        int nx = x + dx[d];
        if (ny >= 0 && ny < H && nx >= 0 && nx < W) {
            if (altitude[ny][nx] < altitude[min_y][min_x]) {
                min_y = ny;
                min_x = nx;
            }
        }
    }

    if (min_y == y && min_x == x) {
        sink[y][x] = {y, x};
    } else {
        sink[y][x] = find_sink(min_y, min_x);
    }

    return sink[y][x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int caseNum = 1; caseNum <= T; caseNum++) {
        cin >> H >> W;

        altitude.assign(H, vector<int>(W));
        sink.assign(H, vector<pair<int, int>>(W, {-1, -1}));

        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
                cin >> altitude[i][j];

        map<pair<int, int>, char> sink_label;
        char label = 'a';
        vector<vector<char>> result(H, vector<char>(W));

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                pair<int, int> s = find_sink(i, j);
                if (sink_label.count(s) == 0)
                    sink_label[s] = label++;
                result[i][j] = sink_label[s];
            }
        }

       
        cout << "Case #" << caseNum << ":\n";
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cout << result[i][j];
                if (j != W - 1) cout << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}
