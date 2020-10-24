/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vll vector<long long>
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)

void solve() {
	ll n, m;
	cin >> n >> m;

	ll sum = 0;
	vll a(n, 0);
	rep(i, n) {
		cin >> a[i];
		sum += a[i];
	}

	if (sum == m) {
		cout << "YES" << '\n';
	} else {
		cout << "NO" << '\n';
	}
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