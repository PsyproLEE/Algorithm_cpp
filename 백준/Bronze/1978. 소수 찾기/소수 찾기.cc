#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> prime_num ;
    for (int i =0 ; i<n; i++){
        cin >> v[i];
    }
    int cnt = 0;
    
    for (int num : v){
        if (num < 2) continue;
        bool is_prime = true;
        for(int i=2; i<= sqrt(num); i++){
            if (num % i == 0){
                is_prime = false;
                break;
            }
        }
        if (is_prime == true){
            cnt ++;
        }
            
    }
    cout << cnt;
}