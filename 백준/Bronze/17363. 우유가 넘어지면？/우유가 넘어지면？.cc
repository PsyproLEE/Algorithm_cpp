#include <iostream>
#include <vector>
using namespace std;

char change(char c) {
    switch (c) {
    case '-': return '|';
    case '|': return '-';
    case '/': return '\\';
    case '\\': return '/';
    case '^': return '<';
    case '<': return 'v';
    case 'v': return '>';
    case '>': return '^';
    default: return c;
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    
    vector<vector<char>> ans(m, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans[m-1-j][i] = change(v[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j];
        }
        cout << '\n'; 
    }

    return 0;
}
