#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> vec;
vector<bool> visited(101,false);
int m,t, cnt = 0;
void bfs(){
    queue<int> q;
    q.push(1);
    visited[1] = true;
    
    while(!q.empty()){
        int current = q.front();
        q.pop();

        for(auto next : vec[current]){
            if(visited[next]) continue;
            q.push(next);
            visited[next] = true;
            cnt++;
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
    bfs();
    cout << cnt;

}