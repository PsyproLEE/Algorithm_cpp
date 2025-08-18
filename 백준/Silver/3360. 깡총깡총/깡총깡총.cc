#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    ll n;
    cin >> n;

    ll a = n / 3;
    ll cnt = 0;
    for (int i = a; i >= 0; --i)
    {
        ll tmp = n;
        tmp -= 3 * i;
        
        cnt += (tmp/2 + 1) % 1000000;
        // cout << cnt<< '\n';
    }
    
    cout << cnt % 1000000;
    
    return 0;
}