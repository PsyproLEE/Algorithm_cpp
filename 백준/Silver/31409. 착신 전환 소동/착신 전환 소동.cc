#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;


int main() {
    int n;
    int cnt = 0;
    cin >> n;
    vector<int> v(n+1);
    for(int i =1; i<=n; ++i){
        cin >> v[i];
        if (v[i] != i) cnt++;
    }

    cout << n - cnt << '\n';
   
    for(int i =1; i<=n; ++i){
        if (v[i] == i) {
            if(i == n)
                v[i] = 1;
            else
                v[i] = i+1;
            }
        cout << v[i] << ' ';
        }
}
