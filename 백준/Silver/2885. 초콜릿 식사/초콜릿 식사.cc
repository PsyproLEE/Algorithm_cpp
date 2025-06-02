#include <iostream>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int K; cin >> K;
    int a = 1;
    int n = 0;

    if (K == 1) return !(cout << 1 << ' ' << 0);  
    
    while(a < K){
        a = a << 1;
        n += 1;
    }
    if (K == a) return !(cout << a << ' ' << 0); 
    
    cout << a << ' ';
    int cnt = 0;
    
     
    while(K != 0){
        a = a >> 1;
        n -= 1;
        cnt += 1;
        if (K - a >= 0)
            K -= a;
    }

    cout << cnt;

    return 0;
}