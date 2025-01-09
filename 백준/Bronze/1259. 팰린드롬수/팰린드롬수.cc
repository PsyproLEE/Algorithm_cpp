#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    
    while(1){
        cin >> s;
        if (s == "0") break;
        bool r = true;
        for (int i =0; i<s.length()/2;i++){
            if(s[i] != s[s.length()-i-1]){
                r = false;
                break;
            }
        }
        if(r) cout << "yes"<<'\n';
        else cout << "no" << '\n';
        
    }
}