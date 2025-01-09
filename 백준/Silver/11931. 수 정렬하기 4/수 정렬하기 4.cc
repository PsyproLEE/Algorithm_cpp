#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector <int> v;
    int n;
    
    cin >> n;

    for(int i =0 ; i<n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    
    sort(v.rbegin(),v.rend());

    for(int x : v) cout << x << '\n';
}