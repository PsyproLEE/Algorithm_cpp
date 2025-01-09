#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int gcd(int x , int y){
    if ( x == 0) return y;
    return gcd(y%x, x);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b,c,d;
    int up = 0, down = 0;
    cin >> a >> b;
    cin >> c >> d;

    a *= d;
    c *= b;
    b *= d;

    up = a + c; down = b;
    cout << up / gcd(up,down)<< " " << down / gcd(up,down);
}   


