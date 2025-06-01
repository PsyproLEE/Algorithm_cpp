#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
struct Node{
    int x, y;
};
vector<Node> nodes;
vector<int> parent;

int N, M;

int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int a , int b){
    int ra = find(a);
    int rb = find(b);
    if (ra != rb) parent[rb] = ra;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;

    nodes.resize(N+1);
    parent.resize(N+1);

    for(int i = 1; i< N+1; ++i){
        cin >> nodes[i].x >> nodes[i].y;
        parent[i] = i;
    }

    int a ,b;
    for (int i = 0; i < M; ++i){
        cin >> a>> b;
        merge(a, b);
    }

    unordered_map<int, int> min_x, max_x, min_y, max_y;

    for (int i = 1; i <= N; ++i){
        int root = find(i);
        int x = nodes[i].x;
        int y = nodes[i].y;

        if (min_x.find(root) == min_x.end()) {
            min_x[root] = max_x[root] = x;
            min_y[root] = max_y[root] = y;
        } else {
            min_x[root] = min(min_x[root], x);
            max_x[root] = max(max_x[root], x);
            min_y[root] = min(min_y[root], y);
            max_y[root] = max(max_y[root], y);
        }

    }
    int result = 1e9;
    for (const auto& entry : min_x) {
        int root = entry.first;
        int width = max_x[root] - min_x[root];
        int height = max_y[root] - min_y[root];
        int perimeter = 2 * (width + height);
        result = min(result, perimeter);
    }

    cout << result << '\n';
    return 0;
}