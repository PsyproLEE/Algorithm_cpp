#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int n;
    cin >> n;

    int year = stoi(s.substr(0, 4));
    int month = stoi(s.substr(5, 2));
    int day = stoi(s.substr(8, 2));

    year += n / 360;
    n %= 360;
    month += n / 30;
    day += n % 30;

    if (day > 30) {
        day -= 30;
        month += 1;
    }
    if (month > 12) {
        month -= 12;
        year += 1;
    }

    cout << year << '-';
    if (month < 10) cout << '0';
    cout << month << '-';
    if (day < 10) cout << '0';
    cout << day << '\n';
}