#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s1 , s2;
    int j = 0, cnt = 0;
    getline(cin,s1);
    getline(cin,s2);
    for (int i =0 ; i<s1.length(); i++){
       if (s1[i] == s2[j]){
            j++;
            if (j>s2.length()-1) {
                j = 0;
                cnt++; 
            }}
       else{ 
            if(j> 0) i -= j;
            j = 0;
        }
    }
    cout << cnt;
}