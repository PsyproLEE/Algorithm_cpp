#include <iostream>

using namespace std;

int d[101][101] = {0,};
int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n;
    cin >> n;
    d[2][1] = 2; // N = 2 일때는 임의로 초기화

    // N = 3 일때부터 시작
    for(int i = 3; i <= n; i++){
        for(int j = 1; j < n; j++){
            // 점화식
            d[i][j] = 2*d[i-1][j] + d[i-1][j-1] + d[i-1][j+1];
            d[i][j] %= 10007;
        }
    }
    int sum = 0;
    // N 일 때 거리가 두 사람 사이의 거리가 1 ~ N-1 경우를 다 더해줘야함
    for(int i = 1; i < n; i++) {
        sum+= d[n][i];
        sum %= 10007;
    }
    cout << sum;
}