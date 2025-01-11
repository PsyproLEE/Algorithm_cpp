#include <iostream>
#include <bits/stdc++.h>
using namespace std;



vector<long long> sieve(long long k){
    vector<long long> primes;
    vector<bool> state (1'000'000'000,true);
    long long n = 2;
    state[1] = false;
    while(1){
    for (long long i =n; i*i<=n+10'000'000; i++){
        if(!state[i]) continue;
        for (long long j = i*i; j<=n+10'000'000; j+=i){
            state[j] = false;     
        }   
    }
    for (long long i = n; i<= n+10'000'000;i++){
        if (state[i]) primes.push_back(i);
    }
    if (primes.size() >= k){
        break;
    }
    n += 10'000'000;
    }
    return primes;
}

int main() 
{   
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long k; cin >> k;
    vector<long long> primes = sieve(k);
    cout << primes[k-1];
}
