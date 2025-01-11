#include <iostream>
#include <bits/stdc++.h>
using namespace std;



vector<int> sieve(int m, int n){
    vector<int> primes;
    vector<bool> state (n+1, true);
    int cnt = 0;
    state[0] = false;
    state[1] = false;
    for (int i =2; i*i<=n; i++){
        if(!state[i]) continue;
        for (int j = i*i; j<=n; j+=i){
            state[j] = false;     
        }   
    }
    for (int i = m ; i< n+1;i++){
        if (state[i]) primes.push_back(i);
    }
    return primes;
}

int main() 
{   
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int m, n; cin >> m >> n;
    for(int a: sieve(m,n))
        cout << a << '\n';
}
