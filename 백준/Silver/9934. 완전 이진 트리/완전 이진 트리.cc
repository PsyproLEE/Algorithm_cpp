#include <iostream>
#include <vector>
using namespace std;

vector<int> tree;
vector<int> input;
int idx = 0;

void inorder(int node) {
    if (node >= tree.size()) return;

    inorder(2 * node);          
    tree[node] = input[idx++];  
    inorder(2 * node + 1);      
}

int main() {
    int k;
    cin >> k;
    int n = (1 << k); // 2^k
    tree.resize(n);   
    input.resize(n - 1);

    for (int i = 0; i < n - 1; ++i) {
        cin >> input[i];
    }

    inorder(1); 
    for (int level = 1; level <= k; ++level) {
        int start = (1 << (level - 1));
        int end = (1 << level);
        for (int i = start; i < end; ++i) {
            cout << tree[i] << ' ';
        }
        cout << '\n';
    }
}
