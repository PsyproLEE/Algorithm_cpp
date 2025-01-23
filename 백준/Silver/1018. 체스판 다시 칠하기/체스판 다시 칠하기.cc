#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int m, n; cin >> m >> n;
    vector<vector<char>> ans1(8,vector<char>(8));
    vector<vector<char>> ans2(8,vector<char>(8));
    vector<vector<char>> v(m,vector<char>(n));
    
    for (int i =0; i< 8; ++i){
        for(int j =0; j<8; ++j){
            if ((i+j) % 2 == 0 )
                ans1[i][j] = 'W';
            else
                ans1[i][j] = 'B';
        }
    }

    for (int i =0; i< 8; ++i){
        for(int j =0; j<8; ++j){
            if ((i+j) % 2 != 0 )
                ans2[i][j] = 'W';
            else
                ans2[i][j] = 'B';
        }
    }
    
    for (int i =0; i< m; ++i){
        for(int j =0; j<n; ++j){
            cin >> v[i][j];
        }
    }
    
    
    int min1 = 5000, min2 = 5000;
    for (int i =0; i<= m-8; ++i){
        for(int j =0; j<=n-8; ++j){
            int cnt = 0;
            for(int k =0; k<8; ++k){
                for (int l =0; l<8 ; ++l){
                    if(ans1[k][l] != v[i+k][j+l])
                        cnt++;
                }
                 
            }
            if (min1 > cnt) min1 = cnt;
        }

    }
    for (int i =0; i<= m-8; ++i){
        for(int j =0; j<=n-8; ++j){
            int cnt = 0;
            for(int k =0; k<8; ++k){
                for (int l =0; l<8 ; ++l){
                    if(ans2[k][l] != v[i+k][j+l])
                        cnt++;
                }
                 
            }
            if (min2 > cnt) min2 = cnt;
        }

    }
    cout << min(min1, min2) ;
}