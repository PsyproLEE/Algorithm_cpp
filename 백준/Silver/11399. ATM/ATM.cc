#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a ,sum = 0;
    vector<int> v;
    cin >> n;

    for (int i =0 ; i<n; i++){
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(),v.end());

    for(int i =0; i<n; i++){
        sum += v[i] * (n - i);
    }
    cout << sum;
}