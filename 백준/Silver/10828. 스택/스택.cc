#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    stack <int> s;
    string str;
    int n; cin >> n;
    
    while (n--){
        cin >> str;
        if (str == "push"){
            int a;
            cin >> a;
            s.push(a);
        }
        else if(str == "top"){
            if (s.empty()) cout << -1 << '\n';
            else cout << s.top() << '\n';
        }
        else if (str == "pop"){
            if (s.empty()) cout << -1 << '\n';
            else{
                cout << s.top() <<'\n';
                s.pop();
            }
        }
        else if (str == "size"){
            cout << s.size() << '\n';
        }
        else if (str == "empty"){
            cout << (s.empty() ? 1 : 0) << '\n';
        }
    }
}