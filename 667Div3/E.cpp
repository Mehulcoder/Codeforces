/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define vll vector<long long>
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define frr(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)


void solve() {
	ll n, k; cin >> n >> k;
	vll x(n), y(n);
	rep(i, n) cin >> x[i];
	rep(i, n) cin >> y[i];

	sort(all(x));
	vll pre(n, 0), suff(n, 0);
	rep(i, n) {
		pre[i] = i - (lower_bound(all(x), x[i] - k) - x.begin() - 1);
	}

	repr(i, n - 1) {
		suff[i] = (upper_bound(all(x), x[i] + k) - x.begin()) - i;
	}

	vll preMax = pre;
	vll suffMax = suff;

	fr(i, 1, n - 1) {
		preMax[i] = max(preMax[i], preMax[i - 1]);
	}

	frr(i, n - 2, 0) {
		suffMax[i] = max(suffMax[i], suffMax[i + 1]);
	}


	ll ans = 0;
	rep(i, n) {
		if (i == n - 1) {
			ans = max(ans, preMax[i]);
		} else {
			ans = max(ans, preMax[i] + suffMax[i + 1]);
		}
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