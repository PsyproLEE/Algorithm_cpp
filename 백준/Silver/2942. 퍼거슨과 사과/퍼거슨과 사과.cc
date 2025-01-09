#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int gcd(int x , int y){
    if (x == 0) return y;
    return gcd(y%x, x);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, g, m;

    cin >> r >> g;

    m = gcd(max(r,g),min(r,g)); // 최대공약수

    vector<int> v ;
    for (int i =1; i<=m; i++){
        if (m % i == 0) {v.push_back(i);}
    }  
    
    for (int n : v){
        cout << n << " " << r / n << " " << g / n <<'\n'; 
    }
}   


