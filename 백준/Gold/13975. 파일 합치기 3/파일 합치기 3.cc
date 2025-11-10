#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    ll t; cin >> t;
    
    while(t--){
        ll k; cin >> k;
        priority_queue<ll, vector<ll>, greater<ll>> pq;

        for(int i =0; i<k; ++i){
            int a; cin >> a;
            pq.push(a);
        }
    
        ll ans = 0;
        while(pq.size()>1){
            ll a = pq.top();
            pq.pop();

            ll b= pq.top();
            pq.pop();

            ans += a+b;
            pq.push(a+b);
            
            
            
        }

        cout << ans << '\n';
    }

    return 0;
}