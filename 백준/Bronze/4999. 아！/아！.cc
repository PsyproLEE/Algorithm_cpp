#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    if (s1.length() >= s2.length()) {
        cout << "go";
    } else { 
        cout << "no";
    }

    return 0;
}
