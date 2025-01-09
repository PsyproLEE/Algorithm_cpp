#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n ;
    
    vector<long long> v;
    long long a;
    for (int i =0 ; i<n; i++){
        cin >> a;
        v.push_back(a); 
    }
    sort(v.begin(),v.end());
    
    cout << v[0] << " " << v[v.size()-1];
    
}