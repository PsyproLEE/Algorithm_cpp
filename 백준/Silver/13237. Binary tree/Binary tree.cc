#include <iostream>
#include <vector>
using namespace std;

int n, root;
vector<int> tree[21]; // 트리 저장
int height[21];       // 노드의 높이 저장

void dfs(int node, int h) {
    height[node] = h; // 현재 노드의 높이 저장
    for (int child : tree[node]) {
        dfs(child, h + 1); // 자식 노드는 현재 높이 +1
    }
}

int main() {
    cin >> n;
    vector<int> parent(n + 1);
    
    for (int i = 1; i <= n; ++i) {
        cin >> parent[i];
        if (parent[i] == -1) {
            root = i; // 루트 노드 찾기
        } else {
            tree[parent[i]].push_back(i); // 부모-자식 관계 설정
        }
    }
    
    dfs(root, 0); // 루트 노드부터 DFS 탐색 시작
    
    for (int i = 1; i <= n; ++i) {
        cout << height[i] << "\n";
    }
    
    return 0;
}