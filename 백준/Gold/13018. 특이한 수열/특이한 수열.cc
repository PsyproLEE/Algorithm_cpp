#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    int n, k;
	cin >> n >> k;
	if(n==k){
		cout << "Impossible";
		return 0;
	}
	cout << n-k << " ";
	for(int i = 1;  i < n-k; i++) cout << i << " ";
	for(int i = n-k+1; i <=n; i++) cout << i << " ";
    return 0;
}