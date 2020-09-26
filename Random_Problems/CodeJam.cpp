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


vll v;
ll n, k;

bool check(ll maxDiff) {
	ll reqd = 0;
	rep(i, n - 1) {
		reqd += ((v[i + 1]  - v[i] - 1) / (maxDiff));
	}

	if (reqd <= k) return 1;

	return 0;
}

void solve(int cass) {
	cin >> n >> k;

	v.resize(n, 0);
	rep(i, n) cin >> v[i];

	ll lo = 1;
	ll hi = 1;
	fr(i, 1, n - 1) {
		hi = max(hi, v[i] - v[i - 1]);
	}

	ll ans = hi;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		if (check(mid)) {
			hi = mid - 1;
			ans = min(ans, mid);
		} else {
			lo = mid + 1;
		}
	}

	cout << "Case #" << cass << ": " << ans << endl;
	return;
}

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	ll t = 1;
	cin >> t;
	ll cass = 1;
	while (t--) {
		solve(cass);
		cass++;
	}

	return 0 ;
}