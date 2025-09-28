#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;
const int MOD = 1000000007;

vector<ll> v;
vector<ll> tree;


void build(int node, int start, int end){
    if(start == end){tree[node] = v[start]; return;}

    int mid = (start + end) / 2;

    build(node*2, start, mid);
    build(node*2+1, mid+1, end);
    tree[node] = (tree[node*2] * tree[node*2+1]) % MOD;

}

void update(int node, int start, int end, int idx, ll val){
    if(start == end){
        tree[node] = val;
        return;
    }

    int mid = (start + end) / 2;
    if (idx <= mid) {
        update(node * 2, start, mid, idx, val);
    } else {
        update(node * 2 + 1, mid + 1, end, idx, val);
    }

    tree[node] = (tree[node*2] * tree[node*2 +1 ]) % MOD;
}

int query(int node, int start, int end, int l , int r){

    if(l > end || r < start) { return 1;}
    if(l <= start && end <= r){ return tree[node];}

    int mid =  (start + end) / 2;
    ll left_res = query(node*2, start, mid, l, r);
    ll right_res = query(node*2 + 1, mid+1, end, l, r);    

    return (left_res * right_res) % MOD;

}



int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    int n, m, k; 
    cin >> n >> m >> k;

    v.assign(n+1,0);
    tree.assign(4 * n, 0); 

    for(int i = 1; i<= n; ++i){
        cin >> v[i];
    }

    build(1,1,n);

    int a; ll b, c;
    for(int i =1; i <= m+k; ++i){
        cin >> a>> b>> c;

        if (a == 1){
            update(1,1,n,b,c);
        }
        else if(a== 2){
            cout << query(1, 1 , n, b, c) << '\n';
        }
    }

    return 0;
}