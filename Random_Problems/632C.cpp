/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vll vector<long long>
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)

void solve() {
	ll n; cin >> n;
	vll a(n + 1, 0), pre(n + 1, 0);
	map<ll, ll> m;
	rep(i, n) {
		cin >> a[i + 1];
	}

	m[0] = 1;
	ll ans = 0, prev = 0;

	fr(i, 1, n) {
		pre[i] = pre[i - 1] + a[i];
		if (m.count(pre[i]))
			prev = max(prev, m[pre[i]]);
		ans += max(0ll, i - prev);
		m[pre[i]] = i + 1;
	}
	cout << ans << '\n';
	return;
}

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	ll t = 1;

	while (t--) {
		solve();
	}

	return 0 ;
}