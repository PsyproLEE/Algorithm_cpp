#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
string str;
set<string> s;
vector<string> v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;

    while(n--){
        cin >> str;
        s.insert(str);
    }

    while(m--){  
        cin >> str;
        if(s.find(str) != s.end()){
            v.push_back(str);
        }
    }
    
    cout << v.size() << '\n';
    sort(v.begin(),v.end());
    for(string a : v){
        cout << a << '\n';
    }
    return 0;
}