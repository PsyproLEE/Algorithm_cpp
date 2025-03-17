#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, order = 1;
    stack<int> s;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        s.push(a);

        while (!s.empty() && s.top() == order) {
            s.pop();
            order++;
        }
    }

    
    if (order == n+1) cout << "Nice";
    else cout << "Sad";
}