#include <iostream>
#include <map>
#include <vector>
using namespace std;

int n, cnt = 0;
string str;
map<string,int> incar;
vector<int> out;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    out.resize(n+1,0);
    for(int i = 1; i <= n; ++i){
        cin >> str;
        incar[str] += i;
    }
    for(int i = 1; i <= n; ++i){
        cin >> str;
        out[i] = incar[str];
        
    }

    for (int i =1; i< n; ++i){
        for(int j = i+1; j<= n; ++j){
            if(out[i] > out[j]) {cnt++; break;}
        }
    }

    cout << cnt;
}
