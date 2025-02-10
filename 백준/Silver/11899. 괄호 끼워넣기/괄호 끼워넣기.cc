#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    stack<char> s;
    int cnt = 0; 

    for (char c : str) {
        if (c == '(') s.push(c); 
        else {
            if (!s.empty() && s.top() == '(') s.pop();  
            else cnt++;
        }
    }
    cnt += s.size();

    cout << cnt;
    
}
