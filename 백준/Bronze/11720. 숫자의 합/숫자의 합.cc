#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n ,sum=0;
    string a;
    cin >> n;
    cin >> a;
    for (int i=0; i<n; i++ ){
        sum += a[i]-'0';
    }
    cout << sum;
}