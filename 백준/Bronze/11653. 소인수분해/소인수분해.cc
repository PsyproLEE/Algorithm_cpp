#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int m = 2;
    cin >> n;

    while (n != 1){
        if (n % m != 0) {m++; continue;}
        else {cout << m <<'\n'; n /= m;}  
    }
}   


