#include <iostream>
#include <bits/stdc++.h>
using namespace std;



int sieve(int n, int k){
    vector<bool> state (n+1, true);
    state[1] = false;
    int cnt = 0;
    for (int i =2; i<=n; i++){
        if(!state[i]) continue;
        cnt++;
        if(cnt == k){
            return i;
        }
        for (int j = i*i; j<=n; j+=i){
            if(state[j])
                {state[j] = false;
                cnt++;}
            if(cnt == k){
                return j;
        }
        }
    }
}

int main() 
{   
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k; cin >> n >> k;

    cout << sieve(n,k);
}
