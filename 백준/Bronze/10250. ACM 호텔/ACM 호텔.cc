#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T ;
    for (int i=0; i<T; i++){
        int H,W,N;
        cin >> H >> W >> N;
        
        int floor = (N % H == 0) ? H : (N%H);
        int room = (N% H == 0) ? (N/H) : (N/H + 1);
        
        int P = floor * 100 + room; 
        cout << P << '\n';
    }
    
    
}