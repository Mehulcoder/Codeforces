/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define vll vector<long long>
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)

void solve() {
	ll n; cin >> n;
	vll a(n, 0);
	rep(i, n) cin >> a[i];
	ll ans = 0;
	ll buffer = 0;
	rep(i, n - 1) {
		a[i] += buffer;
		buffer = 0;
		if (a[i] > 0) {
			buffer = a[i];
			a[i] = 0;
		}
	}
	a[n - 1] += buffer;
	rep(i, n) {
		if (a[i] > 0) ans += a[i];
	}

	cout << ans << '\n';
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