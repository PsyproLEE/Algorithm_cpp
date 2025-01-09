#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int n, m;
    cin >> n;
    for (int i = 0; i<n; i++){
        cin >>m >> s;
        s.erase(m-1,1);
        cout << s<<'\n';
    }

}