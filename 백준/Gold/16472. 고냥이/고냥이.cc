#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    string s;
    cin >> N >> s;

    int kind = 0; // 현재 구간에 존재하는 서로 다른 알파벳 수
    vector<int> cnt(26, 0); // 알파벳 개수 카운팅
    int st = 0, en = 0;
    int answer = 0;

    while (en < s.size()) {
    
        if (cnt[s[en] - 'a'] == 0)
            kind++;
        cnt[s[en] - 'a']++;

        while (kind > N) {
            cnt[s[st] - 'a']--;
            if (cnt[s[st] - 'a'] == 0)
                kind--;
            st++;
        }

        answer = max(answer, en - st + 1);
        en++;
    }

    cout << answer << '\n';
    return 0;
}
