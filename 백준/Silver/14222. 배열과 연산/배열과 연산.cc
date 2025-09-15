#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    int n,k; cin >> n >> k;
    vector<int> v(n+1,-1);
    for (int i =1; i<=n; ++i){
        cin >> v[i];
    }

    sort(v.begin(),v.end());
    int idx = 1;
    while(idx <= n){
        if (idx != v[idx]){
            v[idx] +=k;
            
            if(v[idx] > n){
                cout << 0;
                return 0;
            }
            
            sort(v.begin(),v.end());
            idx = 1;
            continue;
        }
        idx++;
    }

    cout << 1;

    return 0;
}