#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test;
    cin>>test;
 
    for(int i=0; i<test; i++){
 
    int a,b;
    cin>>a>>b;
 
    int cnt=0;
    int sum=0;
 
        for(int i=a; i<=b; i++){
            string str = to_string(i);
            for(int j=0; j<str.length(); j++){
                if(str[j]=='0'){
                    cnt++;
                }
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}


