#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<int>> v(9,vector<int>(9));
    int max = -1;
    int x_idx = -1, y_idx = -1;
    for (int i = 0; i < 9; i++) {   
        for (int j = 0; j < 9; j++) {
            cin >> v[i][j];
            if (v[i][j] > max){
                max = v[i][j];
                y_idx = i+1; x_idx = j+1; 
            }            
        }
        
    }
    cout << max << '\n' << y_idx << " " << x_idx;
}
