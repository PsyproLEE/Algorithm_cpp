#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a;
    vector<int> v(9);
    
    for (int i = 0; i< 9;i++){
        cin >> v[i];
    }
    int max_val = v[0];
    int max_index = 0;
    for (int i =0; i<9 ; i++ ){
        if (v[i]>max_val){ 
            max_val = v[i];
            max_index = i;
        }
    }

    cout << max_val << '\n' << max_index +1 <<'\n';
    
}