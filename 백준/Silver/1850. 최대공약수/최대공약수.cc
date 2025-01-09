#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long  gcd(long long  x , long long y){
    long long r;
    while(x != 0){
        r = x;
        x = y % x;
        y = r; 
    }
    return y;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long a, b;
    cin >> a  >> b;
    long long int m = max(a,b);
    long long int n = min(a,b); 
    for (long long i =0; i< gcd(n,m) ; i++)
        cout<< 1;    

    
}   


