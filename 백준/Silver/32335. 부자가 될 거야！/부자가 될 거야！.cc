#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    for (int i = 0; i < n; ++i) {
        int cur = s[i] - '0';
        int circle = (10 - cur) % 10; 

        if (circle <= m) {
            m -= circle;
            s[i] = '0';
        }
        
       
    }
    s[n-1] = '0' +  ((s[n-1]-'0') + m) % 10;

    cout << s << '\n';
    return 0;
}
