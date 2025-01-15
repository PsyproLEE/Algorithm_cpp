#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n,vector<int>(m));

    for (int i = 0 ;i< n; i++){
        for (int j=0; j< m ; j++){
            cin >> v[i][j];
        }
    }

    int k ; cin >> k;
    int i, j, x, y;
    for (int l = 0; l < k ; l++){
        long long sum = 0;
        cin >> i >> j >> x >>y;
        for (int o = i; o<= x; o++){
            for (int p = j ; p <= y ; p++ ){
                sum += v[o-1][p-1];
            }
        }
        cout << sum << '\n';
    }

}