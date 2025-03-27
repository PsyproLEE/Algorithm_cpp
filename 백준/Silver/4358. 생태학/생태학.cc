#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string,int> tree;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
	cout.precision(4);

    int cnt = 0;
    string str;
    
    while(getline(cin,str)){
        tree[str]++;
        cnt++;
    }

    for(auto i = tree.begin(); i != tree.end(); i++){
        cout << i->first << ' ' << (double) i->second / cnt*100 << '\n';

    }

}
