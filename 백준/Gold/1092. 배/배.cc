#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<int> crane(n);
    for(int i = 0; i < n; ++i){
        cin >> crane[i];
    }

    int m; cin >> m;
    vector<int> box(m);
    for(int i = 0; i < m; ++i){
        cin >> box[i];
    }

    sort(crane.rbegin(), crane.rend()); 
    sort(box.rbegin(), box.rend());     

    if (box[0] > crane[0]) {
        cout << -1 << '\n';
        return 0;
    }

    vector<bool> moved(m, false); 
    int movedCnt = 0;
    int time = 0;

    while(movedCnt < m) {
        int idx = 0;
        for(int i = 0; i < n; ++i) {
            while(idx < m) {
                if (!moved[idx] && crane[i] >= box[idx]) {
                    moved[idx] = true;
                    movedCnt++;
                    idx++;
                    break;
                }
                idx++;
            }
        }
        time++;
    }

    cout << time << '\n';
    return 0;
}
