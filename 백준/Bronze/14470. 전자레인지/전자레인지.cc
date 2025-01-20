#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int a,b,c,d,e; 
    cin >> a >> b >> c>> d>> e;
    int time = 0 ;

    if (a < 0 ){
        time += (-1 * a ) *(c);
        a += (-1 * a );
        if (b>0)
            time += d;
            if (b - a > 0)
                time += (b - a) * e;
    }

    else if( a ==0 ){
        time += d;
        if (b - a > 0)
            time += (b - a) * e;
    }

    else {
        time += (b - a) * e;
    }
    cout << time;
    
}