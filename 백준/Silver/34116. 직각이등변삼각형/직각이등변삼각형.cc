#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if(!(cin >> N)) return 0;

    const long long INF = (1LL<<62);
    long long minY = INF, maxY = -INF;
    long long max_y_minus_x = -INF;   // A = max(y - x)
    long long max_y_plus_x  = -INF;   // B = max(y + x)
    long long min_y_plus_x  = INF;    // S_min = min(x + y)
    long long max_x_minus_y = -INF;   // D = max(x - y)

    for(int i=0;i<N;++i){
        long long x,y; cin >> x >> y;
        minY = min(minY, y);
        maxY = max(maxY, y);
        max_y_minus_x = max(max_y_minus_x, y - x); // A
        max_y_plus_x  = max(max_y_plus_x,  y + x); // B
        min_y_plus_x  = min(min_y_plus_x,  y + x); // S_min
        max_x_minus_y = max(max_x_minus_y, x - y); // D
    }

    // 직각 위쪽
    long long L_up = max_y_minus_x + max_y_plus_x - 2*minY;

    // 직각 아래쪽 (C = -min(x+y) = -S_min)
    long long L_down = 2*maxY - min_y_plus_x + max_x_minus_y;

    long long ans = min(L_up, L_down);
    cout << ans << "\n";
    return 0;
}
