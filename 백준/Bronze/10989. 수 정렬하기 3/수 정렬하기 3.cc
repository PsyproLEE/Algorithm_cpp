#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    int arr [10001]={};
    cin >> n;
    
    int x;
    for (int i = 0; i<n ; i++){
        cin >> x;
        arr[x]++;
    }

    for (int i =0; i<10001; i++){
        for(int j =0 ; j<arr[i]; j++){
            cout << i <<'\n';
        }
    }
    
}