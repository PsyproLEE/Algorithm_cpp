#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    vector<int> v;
    int sum = 0;

    for (int i = 0; i<9 ;i++){
        cin >> n;
        v.push_back(n);
        sum += v[i];
    }   

    sort(v.begin(),v.end());

    int remove1 = -1, remove2 = -1;
    bool is_good = false;
    for(int i =0; i<9 ; i++)
        for(int j =0; j<9 ; j++){
            if(i == j) continue;
            if(sum - v[i] - v[j] == 100){ 
                remove1 = i;
                remove2 = j;
                
                is_good = true;
                break;
                }
        if(is_good) break;}
    for(int i = 0; i<v.size() ; i++){
        if (i != remove1 && i != remove2)
            cout << v[i] << '\n';
    }

}