#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> v(n, 0);
    for (int i = 1; i < n; ++i)
    {
        cin >> v[i];
    }

    int ans = 1;
    for (int i = 1; i < n; ++i)
    {
        int cnt = 1;
        bool flag = false;
        if(n-i < ans) break;
        for (int j = i; j < n; ++j)
        {
            if (v[j] > k){
                if (flag) {
                    break;
                }
                else{
                    flag = true;
                    cnt++;
                }
            }
            else{
                cnt++;
            }
        }
        ans = max(cnt, ans);
    }
    cout << ans;
}