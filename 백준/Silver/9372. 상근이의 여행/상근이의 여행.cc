#include <iostream>
#include <vector>

using namespace std;

int main() {

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<vector<int>> v(n+1,vector<int> (n+1));

        while(m--){
            int start, end; cin >> start >> end;
            v[start].push_back(end);
            v[end].push_back(start);
        }
        cout << n-1 << '\n';
    }
}
