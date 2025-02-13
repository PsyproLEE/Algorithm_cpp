#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> vec;
vector<bool> visited(101,false);
int m,t, cnt = 0;
void dfs(){
    stack<int> s;
    s.push(1);
    while(!s.empty()){
        int current = s.top();
        s.pop();
        
        if(visited[current]) continue;
        visited[current] = true;
        
        if(current != 1) cnt++;
        for(int i =0; i<vec[current].size(); ++i){
            int next = vec[current][vec[current].size()-1-i];
            if(visited[next]) continue;
            s.push(next);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> t;
    vec.resize(m+1);
    while(t--){
        int a , b; cin >> a>> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    dfs();
    cout << cnt;

}