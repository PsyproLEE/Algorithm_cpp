#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<long long,long long> m;
long long n, p, q;

long long numarray(long long n){
    long long ret;
    if(n == 0)
        return 1;
    if (m[n]) return m[n];
    
    m[n] = numarray(n/p) + numarray(n/q);
    return m[n];
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> p >> q;
    m[0] = 1;
    cout << numarray(n);
    
}
