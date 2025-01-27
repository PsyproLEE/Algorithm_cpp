#include <iostream>
#include <vector>
using namespace std;

int integer_count(int n, int m){
    int cnt =0;
    for(int a = 1; a < n ; ++a){
        for(int b = a+1; b < n; ++b){
            if((a*a + b*b + m) % (a*b) == 0){
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;

    while(t--){
        int n , m; cin >> n >> m;
        cout << integer_count(n,m) << '\n';
    }
    return 0;
}
