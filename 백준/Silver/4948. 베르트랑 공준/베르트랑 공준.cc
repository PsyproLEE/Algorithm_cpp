#include <iostream>
#include <bits/stdc++.h>
using namespace std;



vector<long long> sieve(long long n){
    vector<long long> primes;
    vector<bool> state (2*n +1 ,true);
    state[1] = false;

    for (long long i =2; i*i<= 2*n; i++){
        if(!state[i]) continue;
        for (long long j = i*i; j<=2*n; j+=i){
            state[j] = false;     
        }   
    }
    for (long long i = n+1; i<= 2*n;i++){
        if (state[i]) primes.push_back(i);
    }
    
    return primes;
}

int main() 
{   
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long n; 
    while(1){
        cin >> n;
        if (n == 0) break;
        vector<long long> primes = sieve(n);
        cout <<  primes.size() << '\n';
    }
}
