/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
	ll n; cin >> n;

	ll temp = ceil(sqrtl(n));

	if (temp * (temp - 1) >= n) {
		cout << 2 * temp - 3 << '\n';
	} else {
		cout << 2 * temp - 2 << '\n';
	}

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