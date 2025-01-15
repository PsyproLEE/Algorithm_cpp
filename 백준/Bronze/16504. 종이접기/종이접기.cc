#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    long long sum = 0;
    
    for (int i =0; i< n ; i++){
        for (int j =0; j<n ; j++){
            int a; cin >> a;   
            sum += a;
            }
    }
    cout << sum;

}