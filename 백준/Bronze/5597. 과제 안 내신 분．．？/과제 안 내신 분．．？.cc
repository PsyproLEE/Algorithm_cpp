#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x;
    int arr [31]={};
    for (int i =0; i< 28; i++){
        cin >> x;
        arr[x] = 1;
    }

    for (int i = 1; i<=30; i++){
         if (arr[i] != 1) {
            cout << i << '\n';
        }
    }

}