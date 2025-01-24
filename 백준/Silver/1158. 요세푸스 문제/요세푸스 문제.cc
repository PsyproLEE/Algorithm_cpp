#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;

    vector<int> people(n);
    for (int i = 0; i < n; ++i) {
        people[i] = i + 1;
    }

    int idx = 0;
    cout << '<';

    for (int i = 0; i < n; ++i) {
        idx = (idx + k - 1) % people.size(); 
        cout << people[idx]; 
        people.erase(people.begin() + idx);

        if (!people.empty()) {
            cout << ", ";
        }
    }
    cout << '>' << '\n';

    return 0;
}
