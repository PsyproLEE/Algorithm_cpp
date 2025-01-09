#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b){
    if (a ==0) return b;
    return gcd(b%a, a);
}

long long lcm(long long a,long long b){
    return (a*b) / gcd(a,b);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long a = 0,b= 0;
    string s;
    size_t k;
    cin >> s;
    k = s.find(":");
    a = stoll(s.substr(0,k));
    b = stoll(s.substr(k+1));
    cout << a / gcd(a,b) << ":" << b/gcd(a,b) << '\n';
    
}


