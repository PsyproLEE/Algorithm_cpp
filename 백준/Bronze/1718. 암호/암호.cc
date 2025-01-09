#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s1, s2;
    
    getline(cin,s1);
    getline(cin,s2);

    for (int i= 0 ; i< s1.length();i++){
        if (isspace(s1[i])) {cout << s1[i];}  
        else if (s1[i]> s2[i%(s2.length())])
            cout << char (s1[i]  - (s2[i%(s2.length())] - 'a' +1));
        else
            cout << char (s1[i] + ('z' - 'a' + 1) - (s2[i%(s2.length())]  +1 - 'a'));
        }

}