#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    vector<int> v;
    string A;
    int p;
   
    cin >> A >> p;
    v.push_back(stoi(A));
    while(1){
        int next = 0; 
        for(char c : A){
            int tmp = c -'0';
            for (int i =0; i<p -1; ++i){
                tmp *= c -'0';
            }
            next += tmp;
        }
    
        
        for (int i=0; i<v.size(); ++i){
            if (v[i] == next){
                cout << i;
                return 0;
            }
        }
        v.push_back(next);
        A = to_string(next);
        
    }
    return 0;
}