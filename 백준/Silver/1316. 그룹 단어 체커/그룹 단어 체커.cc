#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, cnt = 0;
    cin >> n;

    while (n--) {
        string str;
        cin >> str;

        set<char> s;
        bool is_checker = true;

        for (size_t j = 0; j < str.length(); j++) {
            if (j > 0 && str[j] != str[j - 1] && s.count(str[j])) {
                is_checker = false;
                break;
            }
            s.insert(str[j]);
        }

        if (is_checker) cnt++;
    }

    cout << cnt;
    return 0;
}
