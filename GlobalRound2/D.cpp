/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define vll vector<long long>
#define INF 4557430888798830399ll
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)

/*
* Inspired by: Ecnerwala
* Each row contributes min(s[i+1]-s[i], r-l+1) till i==n-1
* and r-l+1 for i==n-1. Maintain prefixsum of differences.
* Take care of the sortings.
*/

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	ll n; cin >> n;
	vll s(n, 0), diff(n, INF), pref(n, INF);
	rep(i, n) cin >> s[i];

	sort(all(s));
	rep(i, n - 1) diff[i] = s[i + 1] - s[i];

	sort(all(diff));
	rep(i, n - 1) {
		pref[i] = diff[i];
		if (i > 0)pref[i] += pref[i - 1];
	}

	ll q; cin >> q;
	while (q--) {
		ll l, r; cin >> l >> r;
		ll w = (r - l + 1);
		ll ind = lower_bound(all(diff), w) - diff.begin();
		ll ans = (n - ind) * w;
		if (ind > 0) ans += pref[ind - 1];
		cout << ans << ' ';
	}
	cout << '\n';

	return 0 ;
}