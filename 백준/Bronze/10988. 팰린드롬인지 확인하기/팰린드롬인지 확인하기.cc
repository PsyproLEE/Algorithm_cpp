#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a; cin >> a;
    int is_palindrome = 1;
    for(int i =0; i<a.length()/2; i++){
        if(a[i] != a[a.length() -1 -i]) {is_palindrome = 0; break;} 
    }
    cout << is_palindrome;
}