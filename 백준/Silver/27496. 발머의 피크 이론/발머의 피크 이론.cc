#include <iostream>
#include <vector>
using namespace std;

int N, L;
int ans = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); 
    cout.tie(0);
    int sum = 0;
	cin >> N >> L;
    vector<int> v(L,0);
    for(int i =1 ; i<=N ; ++i){
        int tmp;
        sum -= v[i%L];
        cin >> tmp;
        v[i%L] = tmp;
        sum += v[i%L];
          
        if(sum >= 129 && sum <=138){
            ans++;
        }
    }
    cout << ans;
}