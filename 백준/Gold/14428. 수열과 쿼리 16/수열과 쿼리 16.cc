#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int n, m;
 
int arr[100001];
pair<int, int> tree[400004];
 
void init(int start, int end, int cur) {
    if(start == end) {
        tree[cur] = {arr[start], start};
    }
    else {
        int mid = (start+end)/2;
        init(start, mid, cur*2);
        init(mid+1, end, cur*2+1);
        tree[cur] = min(tree[cur*2], tree[cur*2+1]);
    }
}
 
pair<int, int> find(int start, int end, int left, int right, int cur) {
    if(start > right || end < left) return {INF, INF};
    if(left <= start && end <= right) return tree[cur];
    int mid = (start+end)/2;
    return min(find(start, mid, left, right, cur*2), find(mid+1, end, left, right, cur*2+1));
}
 
void update(int start, int end, int idx, int val, int cur) {
    if(start > idx || end < idx) return;
    if(start == end) {
        tree[cur] = {val, idx};
        return;
    }
    int mid = (start+end)/2;
    update(start, mid, idx, val, cur*2);
    update(mid+1, end, idx, val, cur*2+1);
    tree[cur] = min(tree[cur*2], tree[cur*2+1]);
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    init(0, n-1, 1);
    
    cin >> m;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        
        if(a == 1) {
            update(0, n-1, b-1, c, 1);
        }
        else {
            cout << find(0, n-1, b-1, c-1, 1).second+1 << '\n';
        }
    }
}