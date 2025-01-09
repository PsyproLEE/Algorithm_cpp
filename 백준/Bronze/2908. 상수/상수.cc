#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    char temp;

    cin >> s1 >> s2;

    temp = s1[0];
    s1[0] = s1[2];
    s1[2] = temp;
    
    temp = s2[0];
    s2[0] = s2[2];
    s2[2] = temp;

    stoi(s1) > stoi(s2) ?  cout << stoi(s1) : cout << stoi(s2);
}