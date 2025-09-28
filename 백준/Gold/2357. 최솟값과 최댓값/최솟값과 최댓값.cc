#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> // ceil, log2 함수를 사용하기 위해 추가

using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

struct Node{
    int min_val;
    int max_val;
};

vector<Node> tree;
vector<int> arr;

void Build(int node, int start, int end){
    if (start == end){
        tree[node] = {arr[start] , arr[start]};
        return;
    }

    int mid = (start + end) / 2;
    Build(node*2, start, mid);
    Build(node*2 + 1, mid+1, end);
    tree[node].min_val = min(tree[node*2].min_val, tree[node*2+1].min_val);
    tree[node].max_val = max(tree[node*2].max_val, tree[node*2+1].max_val); // <--- 수정된 부분입니다.
}

Node query(int node, int start, int end, int l, int r){
    if(l > end || r < start) { return {INF, 0};}
    if(l <= start && end <= r){ return tree[node];}
    
    int mid =  (start + end) / 2;
    Node left_res = query(node*2, start, mid, l, r);
    Node right_res = query(node*2 + 1, mid+1, end, l , r);
    return {min(left_res.min_val, right_res.min_val), max(left_res.max_val,right_res.max_val)};
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    int n, m; cin >> n >> m;

    arr.assign(n+1,0);

    int h = int(ceil(log2(n)));
    tree.assign(1<<(h+1),{INF,0});
    
    for(int i =1; i<=n; ++i){
        cin >> arr[i];
    }

    Build(1,1,n);

    int a, b;
    for (int i = 0 ; i<m ;++i){
        cin >> a>> b;
        Node result = query(1,1,n,a,b);
        cout << result.min_val <<' ' << result.max_val <<'\n';
    }   

    return 0;
}