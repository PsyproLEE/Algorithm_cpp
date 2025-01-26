#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m, r;
    cin >> n >> m >> r;
    vector<vector<int>> v(n, vector<int>(m));

    // 2차원 배열 입력
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> v[i][j];
        }
    }

    while (r--) {
        int layers = min(n, m) / 2;

        for (int layer = 0; layer < layers; ++layer) {
            int top = layer, bottom = n - 1 - layer;
            int left = layer, right = m - 1 - layer;

           
            int temp = v[top][left]; 

            // 위쪽 가로
            for (int j = left; j < right; ++j)
                v[top][j] = v[top][j + 1];

            // 오른쪽 세로
            for (int i = top; i < bottom; ++i)
                v[i][right] = v[i + 1][right];

            // 아래쪽 가로
            for (int j = right; j > left; --j)
                v[bottom][j] = v[bottom][j - 1];

            // 왼쪽 세로
            for (int i = bottom; i > top; --i)
                v[i][left] = v[i - 1][left];

            v[top + 1][left] = temp; // 임시 저장했던 값 복원
        }
    }



    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
