#include<iostream>
#include<vector>

using namespace std;

int t;            
int m, n;          
int k;              
bool map[50][50]; 

void dfs(int row, int col){
    if(row >= 50 || row < 0) return;
    if(col >= 50 || col < 0) return;

    if(!map[row][col]) return;
    map[row][col] = 0;

    
    dfs(row+1,col);
    dfs(row,col+1);
    dfs(row,col-1);
    dfs(row-1,col);

}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> t;
    while(t--){
        cin >> m >> n >> k;
        for(int j=0;j<k;j++){
            int a, b;
            cin >> a >> b;
            map[a][b]=1;  
        }
        int cnt = 0;  
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(map[row][col]==1){
                    cnt++;
                    dfs(row,col);
                }
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}
