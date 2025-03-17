#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;

    while(t--){
        int a, b, c;
        cin >> a>> b>> c;
        cout << min(a,min(b,c)) <<'\n';
    }
}