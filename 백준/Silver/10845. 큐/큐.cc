#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    deque <int> dq;
    string str;
    int n; cin >> n;
    
    while (n--){
        cin >> str;
        if (str == "push"){
            int a;
            cin >> a;
            dq.push_back(a);
        }
        else if(str == "front"){
            if (dq.empty()) cout << -1 << '\n';
            else cout << dq.front() << '\n';
        }
        else if (str == "pop"){
            if (dq.empty()) cout << -1 << '\n';
            else{
                cout << dq.front() <<'\n';
                dq.pop_front();
            }
        }
        else if (str == "size"){
            cout << dq.size() << '\n';
        }
        else if (str == "empty"){
            cout << (dq.empty() ? 1 : 0) << '\n';
        }
        else if(str == "back"){
            if (dq.empty()) cout << -1 << '\n';
            else cout << dq.back() << '\n';
        }
    }
}