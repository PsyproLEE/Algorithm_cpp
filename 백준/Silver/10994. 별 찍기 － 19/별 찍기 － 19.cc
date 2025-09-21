#include <iostream>
#include <vector>

using namespace std;

// 전역 변수 대신 동적으로 크기를 할당하는 vector 사용
vector<vector<char>> arr;

void draw(int n, int x, int y) {
    
    if (n == 1) {
        arr[x][y] = '*';
        return;
    }


    int len = 4 * n - 3;
    
    for (int i = y; i < y + len; ++i) {
        arr[x][i] = '*';
        arr[x + len - 1][i] = '*';
    }
    
    for (int i = x; i < x + len; ++i) {
        arr[i][y] = '*';
        arr[i][y + len - 1] = '*';
    }
    
    draw(n - 1, x + 2, y + 2);
}

int main() {
    int n;
    cin >> n;

    int size = 4 * n - 3;
    arr.assign(size, vector<char>(size, ' '));

    draw(n, 0, 0);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << arr[i][j];
        }
        cout << '\n';
    }

    return 0;
}