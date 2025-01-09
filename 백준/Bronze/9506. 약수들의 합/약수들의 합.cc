#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(1){
        cin >> n;
        if (n == -1) { break;}
        else{
            int sum = 0;
            vector<int> v;
            for (int i =1; i< n; i++){
                if (n % i == 0) {
                    sum += i;
                    v.push_back(i);
                    }
                }
            
            cout << n;
        
            if (sum == n){
                cout << " = ";
                for (int i  = 0 ; i< v.size() ; i++){
                    cout << v[i];
                    if (i < v.size()-1){
                        cout << " + ";
                    }
                }
                cout << '\n';
                    
            }
            else{
                cout << " is NOT perfect." << '\n';
            } 
        }
    }
}   


