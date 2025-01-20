#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;

	while (t--) {
		string n;
		cin >> n;
		long long love = 0;

		if (n[0] >= '5') {
			love = 5 * pow(10, n.size() - 1) * (5 * pow(10, n.size() - 1) - 1);
		}
		else {
			for (int i = 0; i < n.size(); i++) {
				love += (9 - ((long long)n[i] - '0')) * pow(10, n.size() - i - 1);
			}
			love *= stoi(n);
		}
		cout << love << '\n';
	}
}
