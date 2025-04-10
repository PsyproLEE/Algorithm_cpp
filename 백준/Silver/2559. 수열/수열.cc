#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<int> v (n+1);
    for (int i = 1; i<=n; ++i){
        cin >> v[i];  
    }
    
    int sum = 0;
    for (int i = 1; i <= k; ++i) {
        sum += v[i]; 
    }

    int max_sum = sum;
    for (int i = k + 1; i <= n; ++i) {
        sum += v[i] - v[i - k];  
        max_sum = max(max_sum, sum);
    }


    cout << max_sum;
}
