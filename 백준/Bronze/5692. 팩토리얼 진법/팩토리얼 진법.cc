#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int factorial(int a){
    if (a == 1) return 1;
    return a * factorial (a-1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    while(cin >> s){
        vector<int> v;
        int sum = 0;

        for (int i = s.length() -1 ; i >= 0; --i){
            v.push_back(s[i] -'0');
        }
        if (v[s.length()-1] == 0) break;

        for (int i = s.length() -1 ; i >= 0; --i){
            sum += v[i] * factorial(i+1);
        }
        
        
        cout << sum <<'\n';
    }

}
