#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;
int n;
bool done = false;

bool good(const string &s){
    int m = (int) s.size();
    for(int k = 1; k * 2 <= m; ++k) {
        bool same = true;
        for(int i = 0 ; i<k ; ++i){
            if (s[m -2*k + i] != s[m-k+i]){
                same = false;
                break;
            }
        }
        if (same) return false;
    }
    return true;
}

void dfs(string &s){
    if(done) return;
    if((int)s.size() == n){
        cout << s << '\n';
        done = true;
        return;
    }

    for(char c = '1'; c <= '3'; ++c){
        s.push_back(c);
        if (good(s)) dfs(s);
        s.pop_back();
        if (done) return;
    }
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    string s;
    dfs(s);
    return 0;
}