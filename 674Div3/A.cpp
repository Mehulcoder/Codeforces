/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
	ll n, x; cin >> n >> x;

	if (n == 1 || n == 2) {
		cout << 1 << '\n';
		return;
	}

	cout << (n - 3 + 2 * x) / x << '\n';
	return;
}

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	ll t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0 ;
}