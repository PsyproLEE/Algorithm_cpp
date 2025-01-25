#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    stack <string> s;
    string str;
    int n; cin >> n; cin.ignore();
    
    for (int i =1; i<=n; ++i){
        getline(cin,str);
        istringstream iss(str);
        string word;

        while(iss >> word){
            s.push(word);
        }

        
        cout << "Case #"<< i << ": " ;
        while(!s.empty()){
            cout <<s.top() << ' ';
            s.pop();
            }
        cout << '\n';
    }
}