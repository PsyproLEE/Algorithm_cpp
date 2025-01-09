#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    if (a ==0) return b;
    return gcd(b%a, a);
}

int lcm(int a, int b){
    return a / gcd(a,b) * b;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i =0; i<n ; i++){
        int a, b;
        cin >> a >> b;
        
        cout << lcm(max(a,b),min(a,b)) << ' ';
        cout << gcd(max(a,b),min(a,b)) << '\n';
    } 
}



