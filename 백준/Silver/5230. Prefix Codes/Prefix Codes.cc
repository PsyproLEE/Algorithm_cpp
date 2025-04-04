#include <iostream>
#include <vector>

using namespace std;
void temp(string s, string tree, int t, int cnt){
    if (cnt > s.size()) return;
    if (tree[t] != '*') {cout << tree[t]; t = 0;}
    
    if(s[cnt] == '0'){
        t = 2 * t + 1;
    }
    else {t = 2 * t + 2;}
    temp(s,tree,t, cnt+1);
}
    

int main(){

    int n;
    cin >> n;
    while(n--){
        int k;
        string tree;
        cin >> k >> tree;
        
        while(k--){
            string s;
            cin >> s;
            
            temp(s, tree, 0, 0);
            cout << ' ';
        }
        cout << '\n';

    }


}