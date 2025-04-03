#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> degree(N + 1, 0);
    
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        degree[a]++;
        degree[b]++;
    }
    
    int steps = 0;
    for (int i = 1; i <= N; i++) {
        if (degree[i] > 2) {
            steps += (degree[i] - 2);
        }
    }
    
    cout << steps << endl;
    return 0;
}
