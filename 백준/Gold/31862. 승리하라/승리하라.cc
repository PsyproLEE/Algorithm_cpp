#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

#define INF 0x7FFFFFFF

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll, ll>;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> arr(n+1);
    vector<pii> yet;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(c == 0) yet.push_back({a, b});
        else if(c == 1) arr[a]++;
        else arr[b]++;
    }
    
    int M = 0, cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(arr[i] > M) {
            M = arr[i];
            cnt = 1;
        }
        else if(arr[i] == M) {
            cnt++;
        }
    }

    int ans = 0;
    for(int i = 0; i < (1 << yet.size()); i++) {
        int cM = M, ccnt = cnt;
        for(int j = 0; j < yet.size(); j++) {
            int target = (i&(1<<j)) != 0 ? yet[j].first : yet[j].second;
            arr[target]++;
            if(arr[target] > cM) {
                cM = arr[target];
                ccnt = 1;
            }
            else if(arr[target] == cM) {
                ccnt++;
            }
        }
        if(cM == arr[k] && ccnt == 1) ans++;
        for(int j = 0; j < yet.size(); j++) {
            if((i&(1<<j)) != 0) arr[yet[j].first]--;
            else arr[yet[j].second]--;
        }
    }
    cout << ans;

    return 0;
}
