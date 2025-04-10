#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> v (n+1);

    for (int i = 1; i<=n; ++i){
        cin >> v[i];  
    }
    long long sum =0;
    for (int i = 1; i<= m; ++i){
        sum += v[i];
    }
    long long maxsum = sum; 
    
    for(int i = m+1; i<=n; ++i){
        sum += v[i]-v[i-m];
        maxsum =max(maxsum,sum);
    }
    cout << maxsum;
}
