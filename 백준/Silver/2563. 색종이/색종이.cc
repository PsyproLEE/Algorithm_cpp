#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n; 
    cin >> n;
    int area = 0;
    vector<vector<int>> all(100,vector<int>(100,0));
    vector<pair<int,int>> coordinate(n);
    for (int i =0; i< n; i++){
        cin >> coordinate[i].first >> coordinate[i].second;   
    }

    for (int i =0; i< n; i++){
        int x = coordinate[i].first;
        int y = coordinate[i].second;
        for (int j = 0; j<10 ; j++){
            for(int k=0; k<10 ;k++){
                if (all[x+j][y+k] == 0){
                    all[x+j][y+k] = 1;
                    area++;
                }
            }
        }
        
    }
    cout << area;
}
