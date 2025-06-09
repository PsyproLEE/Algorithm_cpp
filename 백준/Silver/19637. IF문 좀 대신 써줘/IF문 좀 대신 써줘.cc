#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<pair<int,pair<int,string>>> v(N);

int bs(int target) {
    int start = 0, end = N - 1;
    int ans = N - 1; 

    while (start <= end) {
        int mid = (start + end) / 2;
        if (target <= v[mid].first) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return ans;
}


int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    v.resize(N);
    

    for(int i =0; i<N; ++i){
        cin >> v[i].second.second >> v[i].first;
        v[i].second.first = i;
    }
    sort(v.begin(),v.end());
    int tmp;
    for (int i =0; i <M; ++i){
        cin >> tmp;
        cout << v[bs(tmp)].second.second <<'\n';
    }

    return 0;
}