#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string x, y;
    
    int n;
    cin >> n;
    for (int i =0; i< n; i++){
        int cnt = 0;
        cin >> x >> y;
        if (x.length() != y.length())  {cout << "Impossible" << '\n'; continue;}
        
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());

        if (x==y)cout<< "Possible" <<'\n';
        else cout<< "Impossible" <<'\n';
    }
}