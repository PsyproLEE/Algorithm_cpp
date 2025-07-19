#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;
using ll = long long;

vector<int> dx = {0, 1, 0, -1}; 
vector<int> dy = {1, 0, -1, 0};

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int t, r, c;
    string str;

    cin >> t;
    while(t--){
        cin >> r>> c;
        cin.ignore();
        getline(cin, str);

        string bitstring;
        for(auto ch : str){
            int val = (ch ==' ') ? 0 : ch - 'A' + 1;
            bitstring += bitset<5>(val).to_string();
        }
        
        int total = r * c;
        while(bitstring.size() <= total)
            bitstring += '0';

        vector<vector<char>> board(r, vector<char>(c));
        int dir = 0, x =0, y= 0;
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        for(int i = 0; i < total ;++i){
            board[x][y] = bitstring[i];
            visited[x][y] = true;
        
            int nx= x + dx[dir], ny = y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= r || ny >= c || visited[nx][ny]){
                dir = (dir + 1) % 4;
                nx = x + dx[dir];
                ny = y + dy[dir];
            }
            x = nx;
            y = ny;
        }
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cout << board[i][j];
        cout << '\n';


    }

    
    return 0;
}