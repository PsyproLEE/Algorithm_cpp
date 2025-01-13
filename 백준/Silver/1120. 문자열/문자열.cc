#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string a, b;
    cin >> a >> b;

    int ans = 51; 
    for (int i = 0; i <= b.length() - a.length(); i++) {
        int diff = 0;
        for (int j = 0; j < a.length(); j++) {
            if (a[j] != b[i+j]) diff++;           
        }
        ans = min(ans, diff);
    }

    cout << ans;
    return 0;
}
