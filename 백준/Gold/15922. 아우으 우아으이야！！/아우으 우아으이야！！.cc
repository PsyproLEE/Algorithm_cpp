#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    ll n, a ,b;
    ll sum = 0;
    cin >> n;
    cin >> a >>  b;
    
    for(int i =1; i<n; ++i){
        ll tmpa, tmpb;
        cin >> tmpa >> tmpb;

        if(tmpa <= b){
            if (tmpb > b)
                b = tmpb;
            else
                continue;
        }
        else {
            sum += b - a; 
            a = tmpa;
            b = tmpb;
        }
    }

    sum += b-a;
    cout << sum;
    return 0;
}