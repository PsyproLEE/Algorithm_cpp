#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector <int> w;
    vector <int> k;
    for(int i =0 ; i<10; i++){
        int a;
        cin >> a;
        w.push_back(a);
    }

    for(int i =0 ; i<10; i++){
        int a;
        cin >> a;
        k.push_back(a);
    }
    sort(w.rbegin(),w.rend());
    sort(k.rbegin(),k.rend());
    
    cout << w[0] + w[1] + w[2] << ' ';
    cout << k[0] + k[1] + k[2] << ' ';

}