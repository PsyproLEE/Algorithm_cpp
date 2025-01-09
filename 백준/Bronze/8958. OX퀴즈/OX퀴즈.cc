#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int k, sum, n;
    
    cin >> n;
    for (int j = 0 ; j<n; j++){
        cin >> s;
        k =1;
        sum=0;
        for (int i = 0 ; i < s.length(); i++){
            if (s[i] == 'O'){
                sum += k;
                k++;
            }
            else k = 1;
        }
        cout << sum << endl;
    }

}