#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string x, y; cin >> x >> y;
    long long sum= 0;
    for (int i=0; i < x.length(); i++){
        for(int j=0; j<y.length(); j++){
            sum += (x[i] - '0') * (y[j] -'0');
        }

    }
    cout << sum;
}