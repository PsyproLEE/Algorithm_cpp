#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int binarysearch(int target, int n, vector<int> &v){
    int left = 0, right =n-1;
    while(left <= right){
    int mid = (left + right)/ 2;
    if (v[mid] < target){
        left = mid +1; 
    }
    else if (v[mid] > target){
        right = mid- 1;
    }
    else return mid;
    }
    return -1;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int n, m;
    while(cin >> n && n != 0){
        vector<int> v1(n);
        for(int i =0; i< n; ++i){
            cin >> v1[i];
        }
        cin >> m;
        vector<int> v2(m);
        for(int i =0; i< m; ++i){
            cin >> v2[i];
        }
        int sum1 = 0 , sum2 = 0;
        int last_i =0 , last_j =0; 
        int anssum = 0;
        for(int i =0; i<n; ++i){
            int idx = binarysearch(v1[i],m,v2);
            
            if (idx == -1) sum1 += v1[i];
            else { 
                for(int j =last_j; j<idx; ++j){
                    sum2 += v2[j];
                }
                anssum += max(sum1, sum2);
                anssum += v1[i];
                sum1 = 0; sum2 = 0;
                last_i  = i + 1;
                last_j = idx + 1;
            } 
        }
        sum1 =0; sum2 = 0;
        for (int i = last_i; i < n; ++i){
            sum1 += v1[i];
        }
        for (int j = last_j; j < m; ++j){
            sum2 += v2[j];
        }
        cout << anssum + max(sum1, sum2) << '\n';
    }
    return 0;
}