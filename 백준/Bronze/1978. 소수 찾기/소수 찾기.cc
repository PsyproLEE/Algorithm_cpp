#include <bits/stdc++.h>
using namespace std;

#include <iostream>
using namespace std;

vector<int> sieve(int n){
    vector<int> primes;
    vector<bool> state (n+1, true);
    state[1] = false;
    for (int i =2; i*i<=n; i++){
        if(!state[i]) continue;
        for (int j = i*i; j<=n; j+=i){
            state[j] = false;
        }
    }
    for (int i =2; i<= n; i++){
        if(state[i]) primes.push_back(i);
    }
    return primes;
}

int main() 
{   
    int n ; cin >> n;
    vector <int> v(n);
    vector <int> ans;
    int cnt = 0;
    for (int i =0 ; i < n; i++){
        int a; cin >> a;
        v.push_back(a);
    }
    sort(v.rbegin(), v.rend());
    ans = sieve(v[0]);
    for (int a: v){
        for (int b: ans){
            if (a == b) {cnt++; break;}
            else if(a < b) {break;}
        }
    } 
    cout << cnt;
}
