#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    int N, K;

    cin >> N;
    vector<int> v(N);
    set<int> s;
    for (int i = 0; i < N; ++i){
        cin >> v[i];
        s.insert(v[i]);
    }
    K = s.size();
    vector<int> parent(K,-1);
    cout << K << '\n';

    for (int i = 1; i<N; ++i){
        if(parent[v[i]] == -1 && v[i] !=  v[0] ) 
            parent[v[i]] = v[i-1];
    }

    for(int a: parent){
        cout << a << ' ';
    }
    return 0;
}