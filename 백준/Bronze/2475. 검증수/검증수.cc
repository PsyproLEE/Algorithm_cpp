#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long p ,sum = 0;
    for (int i =0 ; i<5; i++){
        cin >> p;
        sum +=p*p;
    }


    cout << sum % 10;

}