#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, t;

    cin >> t;

    while(t--){
        cin >> n;

        
        int maxsum = -1e9, thissum = 0, tmp;
        while(n--){
            cin >> tmp;

            thissum = max(thissum+tmp, tmp);
            maxsum = max(maxsum, thissum);

        }
        cout << maxsum << '\n';
    }

}