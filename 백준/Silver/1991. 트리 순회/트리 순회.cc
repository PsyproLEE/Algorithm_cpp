#include <iostream>
#include <map>

using namespace std;
int n;
map<char, pair<char,char>> tree;

void preorder(char root){
    if (root == '.')
        return;
    cout << root;
    preorder(tree[root].first);
    preorder(tree[root].second);

}

void inorder(char root){
    if (root == '.')
        return;
    
    inorder(tree[root].first);
    cout << root;
    inorder(tree[root].second);

}

void postorder(char root){
    if (root == '.')
    return;

    postorder(tree[root].first);
    postorder(tree[root].second);
    cout << root;

}
int main(){

    cin >> n;
    while(n--){
        char a, b, c;
        cin >> a >> b >> c;
        tree[a].first = b;
        tree[a].second = c; 
    }

    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
}