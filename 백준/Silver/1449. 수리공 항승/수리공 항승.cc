#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int location[1001] = {0,};
    int n, l;
    cin >> n >> l;

    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        location[a] = 1;
    }

    int cnt = n;
    for (int i = 0; i < 1001; ++i) {
        if (location[i] == 1) {
            for (int j = 1; j < l && i + j < 1001; ++j) {  
                if (location[i + j] == 1) cnt--;
            }
            i += l - 1;  
        }
    }
    cout << cnt;
}
