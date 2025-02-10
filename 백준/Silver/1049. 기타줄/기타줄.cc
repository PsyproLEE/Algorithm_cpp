#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m; cin >> n >> m;
    int ans_sets = 10000;
    int ans_one = 10000;
    for (int i =0 ; i<m; ++i){
        int sets, one;
        cin >> sets >> one;
        ans_sets = min(sets,ans_sets);
        ans_one = min(one,ans_one);
    }

    cout << min(min(ans_sets * (n/6) + ans_one* (n%6),ans_sets * (n/6 + 1)),ans_one * n);
}
