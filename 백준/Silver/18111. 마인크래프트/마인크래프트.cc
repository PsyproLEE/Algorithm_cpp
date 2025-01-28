#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, m, b; 
    cin >> n >> m >> b;

    vector<vector<int>> v(n, vector<int>(m));
    int high = -1, sum = 0;
    
    // 입력 및 초기 설정
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> v[i][j];
            high = max(high, v[i][j]);
            sum += v[i][j];
        }
    }

    int min_time = INT_MAX, target_height = 0;

    // 가능한 높이 순회
    for (int h = 0; h <= high; ++h) {
        int time = 0, blocks = b;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (v[i][j] > h) { 
                    time += 2 * (v[i][j] - h);
                    blocks += (v[i][j] - h);
                } else if (v[i][j] < h) {
                    time += (h - v[i][j]);
                    blocks -= (h - v[i][j]);
                }
            }
        }

        if (blocks >= 0 && time <= min_time) {
            min_time = time;
            target_height = h;
        }
    }

    cout << min_time << ' ' << target_height << '\n';
}
