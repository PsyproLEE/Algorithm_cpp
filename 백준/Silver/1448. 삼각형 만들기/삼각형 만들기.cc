#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;
bool istriangle(int a, int b, int c){
    if (a + b <= c) return false;
    else if (a + c <= b) return false;
    else if (b + c <= a) return false;
    return true;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int N; cin >> N;
    v.resize(N);
    
    for(int i =0; i<N; ++i){
        cin >> v[i];
    }
    sort(v.begin(),v.end(),greater<int>());
    for(int i =0; i<N-2; ++i){
        if(istriangle(v[i],v[i+1],v[i+2])) {
            cout << v[i] + v[i+1] + v[i+2];
            return 0;
        } 
    }

    cout << -1;
    return 0;
}