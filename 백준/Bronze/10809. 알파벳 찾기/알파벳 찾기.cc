#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    vector<int> v (26,-1);
   
    getline(cin,s);
    
    for(int i = 0; i<s.length();i++) { 
        if (v[s[i]-'a'] == -1)
            v[s[i]-'a'] = i;
        }

    for (int i =0; i<v.size(); i++) cout << v[i] << " ";
    
}