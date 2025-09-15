#include <iostream>
#include <cmath>
using namespace std;
#define LEN 5000001

int Prime[LEN];

//O(nloglogn)
void erathostenes(){
    Prime[0] = Prime[1] = -1;

    for(int i=2; i<LEN; i++){
        Prime[i] = i;
    }
    int sqrtn = int(sqrt(LEN));

    for(int i=2; i<=sqrtn; i++){
        for(int j=i*i; j<LEN; j+=i){
            if(Prime[j] == j){
                Prime[j] = i;
            }
        }
    }
}

//아마도 O(n) 이하
void Factorization(int num){

    while(num > 1){
        cout << Prime[num] << ' ';
        num /= Prime[num];
    }

    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;

    erathostenes();

    for(int T=0;T<t; T++){
        int num;
        cin >> num;
        Factorization(num);
    }


    return 0;
}
