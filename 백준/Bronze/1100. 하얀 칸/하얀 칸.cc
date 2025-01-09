#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    char s[8][8];
    int x,y,cnt = 0;
    for (int i =0; i<8; i++){
        cin >> s[i];
    }

    for (int x = 0; x<8 ; x++){
        for(int y = 0 ; y<8; y++){
        if ((x+y)%2 == 0 && s[x][y] == 'F'){
                cnt++;
            }

        }
    }
    cout << cnt;
}