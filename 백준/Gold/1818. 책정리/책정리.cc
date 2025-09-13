#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    int n; cin >> n;
    vector<int> v(n), tmp;

    for(int i = 0; i<n; ++i){
        cin >> v[i];
    }

    tmp.push_back(v[0]);

    for(int i =1; i<n; ++i){
        if(v[i] > tmp.back())
            tmp.push_back(v[i]);
        else{
            auto it = lower_bound(tmp.begin(), tmp.end(), v[i]);
            *it = v[i]; 
        }
    }
    
    cout << n- tmp.size();
    return 0;
}