#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int m, n; cin >> n >> m;
    vector<int> v(n);
    for (int i =0; i< n; ++i){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    int ans = -1;
    for(int i =0 ;i<= n-3; ++i){
        for (int j = i+1 ; j<= n-2; ++j){
            for (int k = j+1; k<= n-1; ++k){
                int temp = v[i] + v[j] + v[k];
                if(ans < temp && m >= temp) ans = temp;
            }
        }
       
    }
    cout << ans;
}