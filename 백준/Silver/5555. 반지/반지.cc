#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    string findstring, ringstring;
    cin >> findstring;
    int n ; cin >> n;
    int cnt = 0;
    for (int i =0 ; i< n ; i++){
        cin >> ringstring;
        ringstring += ringstring;

        for (int j = 0 ; j< ringstring.size(); j++){
            if(ringstring.substr(j,findstring.size()) == findstring){
                cnt++;
                break;
            }
        }
    }
    cout << cnt;
}
