#include <iostream>
#include <string>

using namespace std;
bool whoisfront(string a , string b ){
    for(int i = 0; i<min(a.length(), b.length()); ++i){
        a[i] = toupper(a[i]);
        b[i] = toupper(b[i]);
        if (a[i] != b[i]) return a[i] < b[i];
    }
    return a.length() < b.length();
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x = 1;
    
    while(1){
        int n; cin >> n;
        if (n == 0) break;
        string s=""; string ans="";
        for(int i=0; i<n; ++i){
            cin >> s;
            if(i == 0 || whoisfront(s, ans))
                ans = s;
        }
        cout << ans <<'\n';
    }
    
}
