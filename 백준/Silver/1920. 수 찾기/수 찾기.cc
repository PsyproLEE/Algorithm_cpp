#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(int left, int right,int value, vector<int> & v){
    while(left <= right){
        int mid = (left + right)/ 2;

        if(v[mid] == value) return 1;
        else if(v[mid] < value) left = mid +1;
        else right = mid -1;
    }
    return 0;

}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    
    for(int i =0; i<n; ++i){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int t;
    cin >> t;
    int a;
    while(t--){
        cin >> a;
        cout << binarySearch(0,n-1,a,v) <<'\n';
    }
    

    return 0;
}