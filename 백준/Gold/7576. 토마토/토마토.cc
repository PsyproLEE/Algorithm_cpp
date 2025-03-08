#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

vector<vector<int>> box;
vector<vector<bool>> visited;
vector<pair<int,int>> start;
int dx [4] = {1, 0, 0, -1}; 
int dy [4] = {0, 1, -1, 0};
int m, n ,day ;


void bfs(){
    queue<tuple<int,int,int>> q;
    for (int i = 0; i<start.size(); ++i){
        q.push(make_tuple(start[i].first,start[i].second,0));
        visited[start[i].first][start[i].second] = true;
    }

    while(!q.empty()){
        int cury = get<0>(q.front());
        int curx = get<1>(q.front());
        day = get<2>(q.front());
        q.pop();
        
         

        for(int i =0; i< 4; ++i){
            int nexty = cury + dy[i];
            int nextx = curx + dx[i];
            if(nexty >= 0 && nexty < n && nextx >=0 && nextx < m){
                if(box[nexty][nextx] == 0 && !visited[nexty][nextx]){
                    box[nexty][nextx] = 1;
                    visited[nexty][nextx] = true;
                    q.push(make_tuple(nexty,nextx,day+1));
                }
            }

        }
    }

    for(int i = 0; i<n; ++i){
        for(int j =0; j<m; ++j){
            if(box[i][j] == 0) {cout << -1; return;}
        } 
    }

    cout << day;
    return;
}

int main(){
    cin >> m>> n;

    box.assign(n,vector<int>(m));
    visited.assign(n,vector<bool>(m,false));

    for(int i =0; i< n; ++i ){
        for(int j =0; j<m; ++j){
            cin >> box[i][j];
            if (box[i][j] == 1){
                start.push_back({i,j});
            } 
        }
    }
    bfs();

}