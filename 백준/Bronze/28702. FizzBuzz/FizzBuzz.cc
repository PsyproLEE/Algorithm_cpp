#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;

    for (int i = 0; i < 3; i++) {
        cin >> s;

        if (s[0] == 'F' || s[0] == 'B') {
            continue;
        }

        

        int num = stoi(s) + 3 - i;

        if (num % 15 == 0) 
            cout << "FizzBuzz";
        else if (num % 3 == 0)
            cout << "Fizz";
        else if (num % 5 == 0)
            cout << "Buzz";
        else
            cout << num;

        cout << '\n';
        break;
    }

    return 0;
}
