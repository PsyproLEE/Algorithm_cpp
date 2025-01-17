#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    string s; cin >> s;
    vector<string> v;
    for(int i =1; i<=s.length()- 2; i++){
        for (int j = 1;j<=s.length()-i-1 ; j++){
            string s1, s2, s3;

            s1 = s.substr(0,i);
            s2 = s.substr(i,j);
            s3 = s.substr(i+j);

            reverse(s1.begin(),s1.end());
            reverse(s2.begin(),s2.end());
            reverse(s3.begin(),s3.end());
            v.push_back(s1+s2+s3);
        }    
    }
    sort(v.begin(),v.end());
    cout << v[0];
}
