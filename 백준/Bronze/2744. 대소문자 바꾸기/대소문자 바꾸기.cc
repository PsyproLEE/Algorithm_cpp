#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    
    cin >> s;

    for (int i= 0 ; i<s.length(); i++){
        if ('a' <= s[i] && s[i]<= 'z'){
            s[i] = s[i] - ('a'-'A');
        }
    
        else if ('A' <= s[i]&& s[i]<= 'Z'){
            s[i] = s[i] + ('a'-'A');
        }
    }

    cout<< s;
}