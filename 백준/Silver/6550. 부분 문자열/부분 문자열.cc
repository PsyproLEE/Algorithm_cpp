#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s, t;
    
    while(cin >> s >> t){
        bool is_same = false;
        int idx =0;
            for(size_t i = 0; i < t.size(); i++ ){
                if(s[idx] == t[i]){
                    idx++;
                    if (idx >= s.size()){ 
                        is_same = true;
                        break;
                        }
                }
            }
        if (is_same) cout<< "Yes\n";
        else cout << "No\n";
    }

}