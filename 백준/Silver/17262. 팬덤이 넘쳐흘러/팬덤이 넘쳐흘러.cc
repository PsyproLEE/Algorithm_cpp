#include <iostream>

using namespace std;

int main(){
    int n, s, e;
    cin >> n;

    int max_s = 0, min_e = 2e9;
    for(int i = 0; i<n; ++i){
        cin >>s >>e;
        max_s = max(s,max_s);
        min_e = min(e, min_e);
    }

    cout << max(0, max_s -min_e) <<'\n';
}
