#include <iostream>
#include <cstring>

using namespace std;

int cnt = 0;  

int recursion(const char *s, int l, int r) {
    cnt++;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char *s) {
    cnt = 0;
    return recursion(s, 0, strlen(s) - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    char s[1001];

    while (n--) {
  
        cin >> s;
        cout << isPalindrome(s) << " "; 
        cout << cnt << '\n';
    }

    return 0;
}
