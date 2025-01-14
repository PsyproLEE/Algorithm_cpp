#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<vector<char>> v(5, vector<char>(15, '\0')); 
    
    for (int i = 0; i < 5; i++) {   
        string line;
        getline(cin, line);
        for (int j = 0; j < line.size() && j < 15; j++) {
            v[i][j] = line[j];
        }
    }

    for (int j = 0; j < 15; j++) {
        for (int i = 0; i < 5; i++) {
            if (v[i][j] == '\0') continue; 
            cout << v[i][j];
        }
    }
    
}
