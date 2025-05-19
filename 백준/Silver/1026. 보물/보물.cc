#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    vector<int> A(n);
    vector<int> B(n);
    vector<int> Btmp(n);

    for(int i =0; i<n; ++i){
        cin >> A[i];
    }

    for(int i =0; i<n; ++i){
        cin >> B[i];
    }
    Btmp = B;
    sort(A.begin(),A.end());
    sort(Btmp.begin(), Btmp.end(),greater<int>());
    
    int S =0;
    for(int i = 0; i<n; ++i){
        S += A[i] * Btmp[i];
    }
    cout << S;
}
