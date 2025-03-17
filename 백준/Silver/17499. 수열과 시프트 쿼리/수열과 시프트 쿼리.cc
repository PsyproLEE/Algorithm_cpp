#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;

    deque<int> dq(n);
    for (int i = 0; i < n; i++) {
        cin >> dq[i];
    }

    int move = 0;
    while (q--) {
        int op, s, a;
        cin >> op >> s;

        if (op == 1) { 
            cin >> a;
            int idx = (s - 1 - move) % n;
            if (idx < 0) idx += n; 
            dq[idx] += a;
        } 
        else if (op == 2) { 
            move = (move + s) % n; 
        } 
        else if (op == 3) { 
            move = (move - s) % n; 
            if (move < 0) move += n; 
        }
    }

    if (move < 0) {
        move = abs(move);
         while(move--){
                int tmp = dq.front();
                dq.pop_front();
                dq.push_back(tmp);
            }
    }
    else if (move > 0){
        while(move--){
                int tmp = dq.back();
                dq.pop_back();
                dq.push_front(tmp);
                
            }
    }
    

    for (int num : dq) {
        cout << num << ' ';
    }
}
