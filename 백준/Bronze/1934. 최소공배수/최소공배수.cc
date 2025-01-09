#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    if (a ==0) return b;
    return gcd(b%a, a);
}

int lcm(int a, int b){
    return (a*b) / gcd(a,b);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b,t;
    cin >> t;
    for (int i =0; i< t; i++){
        cin >> a >> b;
        cout << lcm(a,b) << '\n';
    }
}


