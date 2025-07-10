#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<long long, long long>> vec;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    long long n, d;
    cin >> n >> d;
    vec.resize(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> vec[i].first >> vec[i].second;
    }

    sort(vec.begin(), vec.end());
    long long st = 0, end = 0, v_ans = 0, v_tmp = 0;
    
    while(st <= end && end < n){
        if(vec[end].first - vec[st].first < d) v_tmp += vec[end++].second;
        else v_tmp -= vec[st++].second;
        v_ans = max(v_tmp, v_ans);
    }
    cout << v_ans;
    return 0;
}