#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    stack<int> st;

    getline(cin,s);

    for(char temp : s){
        if('0'<=temp && temp <= '9')
            st.push(temp-'0');
        else{
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();

            if(temp == '+') st.push(b+a);
            else if(temp == '-') st.push(b-a);
            else if(temp == '*') st.push(b*a);
            else if(temp == '/') st.push(b/a);
            
        }
    }
    cout << st.top() << endl;
}
